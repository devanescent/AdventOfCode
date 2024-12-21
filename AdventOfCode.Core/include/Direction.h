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

	Direction TurnLeft(Direction dir);
	Direction TurnRight(Direction dir);


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
