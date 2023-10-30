#include "Day03_SpiralMemory.h"
#include "Point.h"
#include <map>

namespace AdventOfCode::Year2017::Day03
{
	SpiralMemory::SpiralMemory() : Day(3, "Spiral Memory") { }

	uint64_t SpiralMemory::ExecutePart1(std::vector<std::string> input)
	{
		uint64_t target = std::stoull(input[0]);

		// Full rings are squares of odd numbers: 
		// Ring 0: all values <=1
		// Ring 1: all values <= 3x3=9
		// Ring 2: all values <= 5x5=25
		// Ring 3: all values <= 7x7=49
		// ...

		if (target == 1)
			return 0;

		// Get the ring the target square is on:
		uint64_t root = static_cast<uint64_t>(std::sqrt(target - 1));
		uint64_t ring = root % 2 == 0 ? root / 2 : (root + 1) / 2;

		// Distance to center within a ring oscillates between (ring) and (ring*2)
		// First number on a ring starts one above the ring's bottom right corner
		// -> starting distance = (ring * 2) - 1
		
		return std::abs((int64_t)(((target + (ring * 2 - 1)) % (2 * ring)) - ring)) + ring;
	}

	uint64_t SpiralMemory::ExecutePart2(std::vector<std::string> input)
	{
		uint64_t target = std::stoull(input[0]);
		std::map<Point<int>, int> squares;

		uint64_t lastSquareValue = 0;
		Point currentSquare { 0,0 };
		squares[currentSquare] = 1;

		bool ringStart = true;
		int ring = 0;
		Direction currentDir = Direction::Up;

		while (lastSquareValue <= target)
		{
			if (ringStart)
			{
				++ring;
				++currentSquare.X;
				ringStart = false;
			}
			else switch (currentDir)
			{
				case Direction::Up:
					--currentSquare.Y;
					if (currentSquare.Y == -ring)
						currentDir = Direction::Left;
					break;
				case Direction::Left:
					--currentSquare.X;
					if (currentSquare.X == -ring)
						currentDir = Direction::Down;
					break;
				case Direction::Down:
					++currentSquare.Y;
					if (currentSquare.Y == ring)
						currentDir = Direction::Right;
					break;
				case Direction::Right:
					++currentSquare.X;
					if (currentSquare.X == ring)
					{
						currentDir = Direction::Up;
						ringStart = true;
					}
					break;
			}

			lastSquareValue = 0;
			for (auto&& p : currentSquare.GetSurroundingPoints(true))
				lastSquareValue += squares[p];

			squares[currentSquare] = lastSquareValue;
		}

		return lastSquareValue;
	}
}
