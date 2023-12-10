#pragma once
#include "Point.h"

namespace AdventOfCode::Year2023::Day10
{
	// Used as flags, each pipe has two of them:
	enum PipeConnection
	{
		None = 0,
		North = 1,
		East = 2,
		South = 4,
		West = 8
	};

	class Pipe
	{
	public:
		Point<int> Position;
		unsigned int Connections;

		PipeConnection GetConnectionFrom(const Point<int> p) const
		{
			if (Position.DistanceTo(p) != 1)
				return PipeConnection::None;
			else
			{
				if (Position.X == p.X)
				{
					if (p.Y < Position.Y && (Connections & PipeConnection::North))
					{
						// Other point is north of this and connected via a south pipe:
						return PipeConnection::South;
					}
					else if (p.Y > Position.Y && (Connections & PipeConnection::South))
					{
						// Other point is south of this and connected via a north pipe:
						return PipeConnection::North;
					}
				}
				else if (Position.Y == p.Y)
				{
					if (p.X < Position.X && (Connections & PipeConnection::West))
					{
						// Other point is west of this and connected via an east pipe:
						return PipeConnection::East;
					}
					else if (p.X > Position.X && (Connections & PipeConnection::East))
					{
						// Other point is east of this and connected via a west pipe
						return PipeConnection::West;
					}
				}
			}

			return PipeConnection::None;
		}

		PipeConnection MoveThrough(PipeConnection fromDirection) const
		{
			PipeConnection incoming;
			switch (fromDirection)
			{
				case PipeConnection::None:  return PipeConnection::None;

				case PipeConnection::North: incoming = PipeConnection::South; break;
				case PipeConnection::East:  incoming = PipeConnection::West;  break;
				case PipeConnection::South: incoming = PipeConnection::North; break;
				case PipeConnection::West:  incoming = PipeConnection::East;  break;
			}

			return (PipeConnection)(Connections ^ incoming);
		}
	};
}
