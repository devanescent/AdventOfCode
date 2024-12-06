#pragma once
#include <set>
#include <map>
#include "Point.h"

namespace AdventOfCode::Year2024::Day06
{
	enum class Direction
	{
		Up = 1,
		Right = 2,
		Down = 4,
		Left = 8
	};

	struct Guard
	{
		Point<int> Position;
		Point<int> MoveDir;
		Direction LookDir;

		Guard(Point<int> startPos, Direction startDir) :
			Position(startPos), LookDir(startDir)
		{
			switch (LookDir)
			{
			case Direction::Up:		MoveDir = Point<int>::Up(); break;
			case Direction::Right:	MoveDir = Point<int>::Right(); break;
			case Direction::Down:	MoveDir = Point<int>::Down(); break;
			case Direction::Left:	MoveDir = Point<int>::Left(); break;
			}
		}

		void TurnRight()
		{
			switch (LookDir)
			{
			case Direction::Up:
			{
				LookDir = Direction::Right;
				MoveDir = Point<int>::Right();
				break;
			}
			case Direction::Right:
			{
				LookDir = Direction::Down;
				MoveDir = Point<int>::Down();
				break;
			}
			case Direction::Down:
			{
				LookDir = Direction::Left;
				MoveDir = Point<int>::Left();
				break;
			}
			case Direction::Left:
			{
				LookDir = Direction::Up;
				MoveDir = Point<int>::Up();
				break;
			}
			}
		}

		Point<int> GetNextPosition() const
		{
			return Position.MoveBy(MoveDir.X, MoveDir.Y);
		}

		bool IsPosWithinMap(int mapHeight, int mapWidth) const
		{
			return Position.IsXBetween(0, mapWidth - 1) && Position.IsYBetween(0, mapHeight - 1);
		}

		bool FindLoop(const std::set<Point<int>>& obstacles, int mapHeight, int mapWidth)
		{
			// Keep track of which obstacles have been hit from which direction(s):
			std::map<Point<int>, Direction> obstaclesHit;

			while (IsPosWithinMap(mapHeight, mapWidth))
			{
				Point<int> nextPos = GetNextPosition();
				if (!obstacles.contains(nextPos))
				{
					// Not obstructed, move forward:
					Position = nextPos;
				}
				else
				{
					// Has obstacle been hit before?
					auto hitIt = obstaclesHit.find(nextPos);
					if (hitIt != obstaclesHit.end() && ((int)hitIt->second & (int)LookDir))
					{
						// Loop detected:
						return true;
					}

					// Remember obstacle with direction(s):
					auto obsIt = obstaclesHit.find(nextPos);
					if (obsIt == obstaclesHit.end())
						obstaclesHit.emplace(nextPos, LookDir);
					else
						obsIt->second = (Direction)((int)(obsIt->second) | (int)LookDir);

					// Turn before the obstacle and continue next turn:
					TurnRight();
				}
			}

			// Out of bounds, no loop:
			return false;
		}
	};
}
