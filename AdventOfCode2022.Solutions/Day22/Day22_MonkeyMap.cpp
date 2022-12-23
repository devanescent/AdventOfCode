#include "Day22_MonkeyMap.h"

namespace AdventOfCode::Year2022::Day22
{
	MonkeyMap::MonkeyMap() : DayTC(22, "Monkey Map") { }

	enum class Direction
	{
		// In right-turn order and by passwort points:
		Right = 0,
		Down = 1,
		Left = 2,
		Up = 3
	};

	uint64_t MonkeyMap::ExecutePart1(std::vector<MoveInstruction> moves, JungleMap map)
	{
		// Start: Left bound of topmost row:
		Point<int> pos(map.XBounds[0].Start, 0);
		Direction facing = Direction::Right;

		for (const MoveInstruction& move : moves)
		{
			switch (move.MoveType)
			{
			case MoveInstructionType::TurnRight:
				// Next value in enum:
				facing = static_cast<Direction>((static_cast<int>(facing) + 1) % 4);
				break;
			case MoveInstructionType::TurnLeft:
				// Previous value in enum:
				facing = static_cast<Direction>((static_cast<int>(facing) + 3) % 4);
				break;
			case MoveInstructionType::Forward:
				// Walk in the given direction until a wall is hit:
				for (int step = 0; step < move.MoveTiles; ++step)
				{
					auto next = [&]()
					{
						switch (facing)
						{
							case Direction::Up:
							{
								auto next = pos.MoveYBy(-1);
								if (next.Y < map.YBounds[next.X].Start)
									next.Y = map.YBounds[next.X].End;
								return next;
							}
							case Direction::Right:
							{
								auto next = pos.MoveXBy(1);
								if (next.X > map.XBounds[next.Y].End)
									next.X = map.XBounds[next.Y].Start;
								return next;
							}
							case Direction::Down:
							{
								auto next = pos.MoveYBy(1);
								if (next.Y > map.YBounds[next.X].End)
									next.Y = map.YBounds[next.X].Start;
								return next;
							}
							case Direction::Left:
							{
								auto next = pos.MoveXBy(-1);
								if (next.X < map.XBounds[next.Y].Start)
									next.X = map.XBounds[next.Y].End;
								return next;
							}
						}
					}();

					// Check for wall:
					if (map.Walls.contains(next))
						break; // Stop moving immediately when hitting a wall
					else
						pos = next;
				}
				break;
			}
		}

		// The final password is the sum of ...
		// (use 1-based indices)
		return 
			(pos.Y + 1) * 1000 +      // 1000 times the row ...
			(pos.X + 1) * 4 +         // 4 times the column ...
			static_cast<int>(facing); // ... and the facing
	}

	uint64_t MonkeyMap::ExecutePart2(std::vector<MoveInstruction> moves, JungleMap map)
	{
		return uint64_t();
	}
}
