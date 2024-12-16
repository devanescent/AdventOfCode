#include "Day15_WarehouseWoes.h"
#include <algorithm>
#include <numeric>
#include <set>

namespace AdventOfCode::Year2024::Day15
{
	WarehouseWoes::WarehouseWoes() : DayTC(15, "Warehouse Woes") { }

	uint64_t WarehouseWoes::ExecutePart1(std::vector<Point<int>> movements, GridMap map)
	{
		// Set initial position of the robot to free space for processing:
		Point<int> robot = map.Find('@');
		map.Replace(robot, '.');

		// Process movements:
		for (const auto& mv : movements)
		{
			auto nextRobotPos = robot + mv;
			auto nextSpace = map.Get(nextRobotPos);
			
			switch (nextSpace)
			{
				case '.':
					// Free space in front of the robot: move forward
					robot = nextRobotPos;
					break;
				case '#':
					// Wall, movement is blocked:
					break;
				case 'O':
					// Move box if possible:
					// Find first position in current direction that's not a box:
					auto posAfterBoxes = nextRobotPos + mv;
					while (map.Get(posAfterBoxes) == 'O')
						posAfterBoxes = posAfterBoxes + mv;

					// If free space is found, robot moves all box one step further
					if (map.Get(posAfterBoxes) == '.')
					{
						map.Swap(nextRobotPos, posAfterBoxes);
						robot = nextRobotPos;
					}
					
					// Otherwise, if it's a wall, nothing gets moved
					break;
			}
		}

		// Get all boxes and their GPS coordinates:
		std::vector<Point<int>> boxes;
		map.Find(std::back_inserter(boxes), 'O');

		return std::accumulate(boxes.begin(), boxes.end(), 0ull,
			[](uint64_t gpsCoordSum, const Point<int>& box)
			{
				return gpsCoordSum + box.Y * 100 + box.X;
			});
	}

	// Recursivly check if box can be moved by checking box(es) behind it (in move direction)
	bool CanMoveBox(const Point<int>& box, const GridMap& map, const Point<int>& moveDir, std::vector<Point<int>>& boxesToMove)
	{
		// Check if box was already checked:
		if (std::find(boxesToMove.begin(), boxesToMove.end(), box) != boxesToMove.end())
			return true;
		else
			boxesToMove.push_back(box);

		// Check if there is space to move the current box:
		auto spaceBehindLeftHalf = map.Get(box + moveDir);
		auto spaceBehindRightHalf = map.Get(box.MoveXBy(1) + moveDir);

		if (spaceBehindLeftHalf == '.' && spaceBehindRightHalf == '.')
			// Both halves have free space behind them => Box can be moved
			return true;
		else if (spaceBehindLeftHalf == '#' || spaceBehindRightHalf == '#')
			// At least one half has a wall behind it => Box is blocked
			return false;
		else if (spaceBehindLeftHalf == '[')
		{
			// Single box behind current box => check if it can be moved
			return CanMoveBox(box + moveDir, map, moveDir, boxesToMove);
		}
		else
		{
			// Check each half for a box behind it:
			bool canMoveLeftHalf = spaceBehindLeftHalf == ']' ? CanMoveBox(box.MoveXBy(-1) + moveDir, map, moveDir, boxesToMove) : true;
			
			// If left side cannot be moved, no need to check right side:
			if (!canMoveLeftHalf)
				return false;

			bool canMoveRightHalf = spaceBehindRightHalf == '[' ? CanMoveBox(box.MoveXBy(1) + moveDir, map, moveDir, boxesToMove) : true;
			return canMoveRightHalf;
		}
	}

	uint64_t WarehouseWoes::ExecutePart2(std::vector<Point<int>> movements, GridMap map)
	{
		// Widen the map and replace original map with it:
		std::vector<std::string> wideMap(map.Height(), std::string(map.Width() * 2, '.'));
		map.Transform([&wideMap](int x, int y, char tile)
			{
				switch (tile)
				{
					case '#':
						wideMap[y][x * 2] = '#';
						wideMap[y][x * 2 + 1] = '#';
						break;
					case 'O':
						wideMap[y][x * 2] = '[';
						wideMap[y][x * 2 + 1] = ']';
						break;
					case '@':
						wideMap[y][x * 2] = '@';
						break;
				}
			});
		map = GridMap(std::move(wideMap));

		// Set initial position of the robot to free space for processing:
		Point<int> robot = map.Find('@');
		map.Replace(robot, '.');

		// Process movements:
		for (const auto& mv : movements)
		{
			auto nextRobotPos = robot + mv;
			auto nextSpace = map.Get(nextRobotPos);

			switch (nextSpace)
			{
				case '.':
					// Free space in front of the robot: move forward
					robot = nextRobotPos;
					break;
				case '#':
					// Wall, movement is blocked:
					break;
				case '[': case ']':
					// Horizontal movement
					if (mv == Point<int>::Left() || mv == Point<int>::Right())
					{
						// Move box if possible:
						// Find first space in current direction that's not a box:
						auto posAfterBoxes = nextRobotPos + mv;
						char spaceAfterBoxes = map.Get(posAfterBoxes);
						while (spaceAfterBoxes == '[' || spaceAfterBoxes == ']')
						{
							posAfterBoxes = posAfterBoxes + mv;
							spaceAfterBoxes = map.Get(posAfterBoxes);
						}

						// If free space is found, robot moves all box one step further
						// Swap each adjacent tile, starting from the free space at the end:
						if (spaceAfterBoxes == '.')
						{
							// If robot moves right, swap box tiles right to left and vice versa:
							int dx = mv == Point<int>::Right() ? -1 : 1;
							for (int x = posAfterBoxes.X; x != nextRobotPos.X; x += dx)
							{
								map.Swap(Point<int>(x, robot.Y), Point<int>(x + dx, robot.Y));
							}
							robot = nextRobotPos;
						}
						// Otherwise, if it's a wall, nothing gets moved
					}
					// Vertical movement
					else
					{
						Point<int> box = nextSpace == '[' ? nextRobotPos : nextRobotPos.MoveXBy(-1);
						std::vector<Point<int>> boxesToMove;
						if (CanMoveBox(box, map, mv, boxesToMove))
						{
							// Move all boxes, starting from the ones the furthest away
							auto boxSorter = mv == Point<int>::Up() ?
								// Order boxes from top to bottom:
								[](const Point<int>& box1, const Point<int>& box2) { return box1.Y < box2.Y; } :
								// Order boxes from bottom to top:
								[](const Point<int>& box1, const Point<int>& box2) { return box1.Y > box2.Y; };

							std::sort(boxesToMove.begin(), boxesToMove.end(), boxSorter);
							for (const auto& box : boxesToMove)
							{
								map.Swap(box, box + mv);
								map.Swap(box.MoveXBy(1), box.MoveXBy(1) + mv);
							}
							robot = nextRobotPos;
						}
						// Otherwise at least one box is blocked by a wall so nothing gets moves
					}
					break;
			}
		}

		// Get all boxes and their GPS coordinates (from the left half):
		std::vector<Point<int>> boxes;
		map.Find(std::back_inserter(boxes), '[');

		return std::accumulate(boxes.begin(), boxes.end(), 0ull,
			[](uint64_t gpsCoordSum, const Point<int>& box)
			{
				return gpsCoordSum + box.Y * 100 + box.X;
			});
	}
}
