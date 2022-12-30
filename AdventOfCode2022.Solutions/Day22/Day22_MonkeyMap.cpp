#include "Day22_MonkeyMap.h"
#include <map>

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
		
		/* Map all borders and their transitions:
		       ___ ___ 
		     A| B | C |
		      |___|___|D
		     N|   | E
		   ___|___|F
		  | M |   |
		 L|___|___|G
		  |   | H
		 K|___|I
			J
		
		*/
		std::map<Point<int>, std::pair<Point<int>, Direction>> transitions;

		// A -> L, invert vertically
		for (int y = 0; y < 50; ++y)
			transitions[{49, y}] = std::make_pair(Point<int>(0, 149 - y), Direction::Right);

		// B -> K, left-right to top-bottom
		for (int x = 0; x < 50; ++x)
			transitions[{50 + x, -1}] = std::make_pair(Point<int>(0, 150 + x), Direction::Right);

		// C -> J, keep left-right order
		for (int x = 0; x < 50; ++x)
			transitions[{100 + x, -1}] = std::make_pair(Point<int>(x, 199), Direction::Up);

		// D -> G, invert vertically
		for (int y = 0; y < 50; ++y)
			transitions[{150, y}] = std::make_pair(Point<int>(99, 149 - y), Direction::Left);

		// E -> F, left-right to top-bottom
		for (int x = 0; x < 50; ++x)
			transitions[{100 + x, 50}] = std::make_pair(Point<int>(99, 50 + x), Direction::Left);

		// F -> E, top-bottom to left-right
		for (int y = 0; y < 50; ++y)
			transitions[{100, 50 + y}] = std::make_pair(Point<int>(100 + y, 49), Direction::Up);

		// G -> D, invert vertically
		for (int y = 0; y < 50; ++y)
			transitions[{100, 100 + y}] = std::make_pair(Point<int>(149, 49 - y), Direction::Left);

		// H -> I, left-right to top-bottom
		for (int x = 0; x < 50; ++x)
			transitions[{50 + x, 150}] = std::make_pair(Point<int>(49, 150 + x), Direction::Left);

		// I -> H, top-bottom to left-right
		for (int y = 0; y < 50; ++y)
			transitions[{50, 150 + y}] = std::make_pair(Point<int>(50 + y, 149), Direction::Up);

		// J -> C, keep left-right order
		for (int x = 0; x < 50; ++x)
			transitions[{x, 200}] = std::make_pair(Point<int>(100 + x, 0), Direction::Down);

		// K -> B, top-bottom to left-right
		for (int y = 0; y < 50; ++y)
			transitions[{-1, 150 + y}] = std::make_pair(Point<int>(50 + y, 0), Direction::Down);

		// L -> A, invert vertically
		for (int y = 0; y < 50; ++y)
			transitions[{-1, 100 + y}] = std::make_pair(Point<int>(50, 49 - y), Direction::Right);

		// M -> N, left-right to top-bottom
		for (int x = 0; x < 50; ++x)
			transitions[{x, 99}] = std::make_pair(Point<int>(50, 50 + x), Direction::Right);

		// N -> M, top-bottom to left-right
		for (int y = 0; y < 50; ++y)
			transitions[{49, 50 + y}] = std::make_pair(Point<int>(y, 100), Direction::Down);

		// Three corners (E-F, H-I, M-N) are used twice in the transitions above: handle separately
		std::map<std::pair<Point<int>, Direction>, std::pair<Point<int>, Direction>> cornerTransitions;
		cornerTransitions[std::make_pair(Point<int>(100, 50), Direction::Down)] = std::make_pair(Point<int>(99, 50), Direction::Left); // E -> F
		cornerTransitions[std::make_pair(Point<int>(100, 50), Direction::Right)] = std::make_pair(Point<int>(100, 49), Direction::Up); // F -> E

		cornerTransitions[std::make_pair(Point<int>(50, 150), Direction::Down)] = std::make_pair(Point<int>(49, 150), Direction::Left); // H -> I
		cornerTransitions[std::make_pair(Point<int>(50, 150), Direction::Right)] = std::make_pair(Point<int>(50, 149), Direction::Up); // I -> H

		cornerTransitions[std::make_pair(Point<int>(49, 99), Direction::Up)] = std::make_pair(Point<int>(50, 99), Direction::Right); // M -> N
		cornerTransitions[std::make_pair(Point<int>(49, 99), Direction::Left)] = std::make_pair(Point<int>(49, 100), Direction::Down); // N -> M

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
						auto next = pos;
						auto nextFacing = facing;
						switch (facing)
						{
							case Direction::Up: next = pos.MoveYBy(-1); break;
							case Direction::Right: next = pos.MoveXBy(1); break;
							case Direction::Down: next = pos.MoveYBy(1); break;
							case Direction::Left: next = pos.MoveXBy(-1); break;
						}

						// Check for corner transition first, then for the remaining edges:
						auto cornerTransIt = cornerTransitions.find(std::make_pair(next, facing));
						if (cornerTransIt != cornerTransitions.end())
						{
							next = cornerTransIt->second.first;
							nextFacing = cornerTransIt->second.second;
						}
						else
						{
							auto transIt = transitions.find(next);
							if (transIt != transitions.end())
							{
								next = transIt->second.first;
								nextFacing = transIt->second.second;
							}
						}

						// Check for wall:
						if (map.Walls.contains(next))
							break; // Stop moving immediately when hitting a wall
						else
						{
							// Otherwise, update position and facing
							pos = next;
							facing = nextFacing;
						}
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
}
