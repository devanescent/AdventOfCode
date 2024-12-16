#pragma once

namespace AdventOfCode
{
	// Default direction definition
	// Order must be in clockwise direction order and values must be 0..3 for the turn implementation to work.

	// If a custom definition is required by the task, define AOC_CUSTOM_DIR and a custom enum named Direction
	// before including this header

#ifndef AOC_CUSTOM_DIR
	enum class Direction
	{
		Up,
		Right,
		Down,
		Left
	};
#endif // AOC_CUSTOM_DIR

	Direction TurnLeft(Direction dir)
	{ 
#ifndef AOC_CUSTOM_DIR
		return static_cast<Direction>((static_cast<int>(dir) + 3) % 4);
#else
		switch (dir)
		{
			case Direction::Up:		return Direction::Left;
			case Direction::Right:	return Direction::Up;
			case Direction::Down:	return Direction::Right;
			case Direction::Left:	return Direction::Down;
			default:						return dir;
		}
#endif
	}

	Direction TurnRight(Direction dir)
	{
#ifndef AOC_CUSTOM_DIR
		return static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
#else
		switch (dir)
		{
			case Direction::Up:		return Direction::Right;
			case Direction::Right:	return Direction::Down;
			case Direction::Down:	return Direction::Left;
			case Direction::Left:	return Direction::Up;
			default:						return dir;
		}
#endif
	}

	// Enable point functions by including "Point.h" before "Direction.h"

#ifdef AOC_POINT
	template<typename T>
	Point<T> MoveForward(const Point<T>& p, Direction dir)
	{
		switch (dir)
		{
			case Direction::Up:		return p.MoveYBy(-1);
			case Direction::Down:	return p.MoveYBy(1);
			case Direction::Left:	return p.MoveXBy(-1);
			case Direction::Right:	return p.MoveXBy(1);
			default: return p;
		}
	}

#endif //  AOC_POINT
}
