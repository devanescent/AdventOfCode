#include "NanobotProcessor.h"
#include <regex>

namespace AdventOfCode::Year2018::Day23
{
	std::vector<Nanobot> NanobotProcessor::Process(std::vector<std::string> input)
	{
		std::regex pattern("pos=<(-?[0-9]+),(-?[0-9]+),(-?[0-9]+)>, r=([0-9]+)");
		std::smatch matches;

		std::vector<Nanobot> result;
		result.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(result),
			[&pattern](const std::string& line)
			{
				std::smatch matches;
				std::regex_search(line, matches, pattern);
				return Nanobot(
					atoi(matches[1].str().c_str()),
					atoi(matches[2].str().c_str()),
					atoi(matches[3].str().c_str()),
					atoi(matches[4].str().c_str())
				);
			}
		);

		return result;
	}
}
