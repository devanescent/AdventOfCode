#include "Direction.h"

namespace AdventOfCode
{
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
}
