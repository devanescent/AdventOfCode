#pragma once
#include <Point.h>

namespace AdventOfCode::Year2018::Day20
{
	enum class DoorFlags
	{
		None = 0,

		North = 1,
		East = 2,
		South = 4,
		West = 8
	};

	inline DoorFlags operator|(DoorFlags a, DoorFlags b)
	{
		return static_cast<DoorFlags>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline DoorFlags& operator|=(DoorFlags& a, DoorFlags b)
	{
		a = a | b;
		return a;
	}

	inline bool operator&(DoorFlags a, DoorFlags b)
	{
		return (static_cast<int>(a) & static_cast<int>(b)) != 0;
	}

	class Room
	{
	public:
		Point<int> Location;
		DoorFlags Doors = DoorFlags::None;
		int DistanceFromOrigin;

		Room(Point<int> loc, DoorFlags doors, int distance = -1) : Location(loc), Doors(doors), DistanceFromOrigin(distance) {}

		bool operator<(const Room& other) const
		{
			// For priority queue, returning true means this element has lower priority than the other element:
			// Elements with higher distance from origin have higher prio (depth-first)
			return DistanceFromOrigin < other.DistanceFromOrigin;
		}
	};
}
