#include "DiveCmdProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2021::Day02
{
	std::vector<DiveCmd> DiveCmdProcessor::Process(std::vector<std::string> input)
	{
		std::vector<DiveCmd> result;
		result.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(result),
			[](const std::string s)
			{
				// Parse each line to the corresponding command:
				
				if (!s.empty())
				{
					// The first letter is different in each command so this is sufficient to find the correct command
					// The rest of the string after the command name is its value (+1 for also skipping the space)
					switch (s[0])
					{
					case 'f':
						return DiveCmd(DiveCmdDirection::Forward, std::stoi(s.substr(strlen("forward") + 1)));
					case 'u':
						return DiveCmd(DiveCmdDirection::Up, std::stoi(s.substr(strlen("up") + 1)));
					case 'd':
						return DiveCmd(DiveCmdDirection::Down, std::stoi(s.substr(strlen("down") + 1)));
					}
				}

				// possible empty lines:
				return DiveCmd();
			});

		return result;
	}
}