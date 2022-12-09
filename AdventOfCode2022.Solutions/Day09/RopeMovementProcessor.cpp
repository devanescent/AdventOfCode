#include "RopeMovementProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day09
{
	std::vector<RopeMovement> RopeMovementProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RopeMovement> movements;
		movements.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(movements),
			[](const std::string& line)
			{
				return RopeMovement
				{ 
					static_cast<Direction>(line[0]),
					std::stoi(line.substr(2))
				};
			}
		);

		return movements;
	}
}
