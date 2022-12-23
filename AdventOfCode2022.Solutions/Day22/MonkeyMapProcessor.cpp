#include "MonkeyMapProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2022::Day22
{
	std::pair<std::vector<MoveInstruction>, JungleMap> MonkeyMapProcessor::Process(std::vector<std::string> input)
	{
		std::vector<MoveInstruction> moves;

		// Input lines are not filled with trailing spaces!
		size_t mapWidth = std::max_element(input.begin(), input.end(),
			[](const std::string& line1, const std::string& line2) { return line1.length() < line2.length(); }
		)->length();

		// Map height is input size reduced by two because of the move instructions
		// at the end (which is separated from the map with an empty line):
		size_t mapHeight = input.size() - 2;

		JungleMap map(mapHeight, mapWidth);

		// Collect map data:
		for (int y = 0; y < input.size() - 2; ++y)
		{
			auto& xBounds = map.XBounds[y]; // y = current row

			for (int x = 0; x < input[y].size(); ++x)
			{
				const auto tile = input[y][x];
				
				if (tile == ' ')
					continue;
				else if (xBounds.Start == -1) // only set once
					xBounds.Start = x;

				xBounds.End = x;

				auto& yBounds = map.YBounds[x]; // x = current column
				if (yBounds.Start == -1) yBounds.Start = y; // only set once
				yBounds.End = y;

				if (tile == '#')
					map.Walls.emplace(x, y);
			}
		}

		// Collect move instructions:
		std::istringstream iss(input.back());
		bool isForward = true; // instructions start with a number

		int stepsForward;
		char turnDirection;

		while (iss)
		{
			if (isForward && iss >> stepsForward)
				moves.emplace_back(MoveInstruction{ MoveInstructionType::Forward, stepsForward });
			else if (!isForward && iss >> turnDirection)
				moves.emplace_back(MoveInstruction{ turnDirection == 'R' ? MoveInstructionType::TurnRight : MoveInstructionType::TurnLeft, 0 });

			// alternate between moving forward and turning either left or right:
			isForward = !isForward;
		}

		return std::make_pair(moves, map);
	}
}
