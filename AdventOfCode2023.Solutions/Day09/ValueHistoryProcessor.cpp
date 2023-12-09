#include "ValueHistoryProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day09
{
	std::vector<ValueHistory> ValueHistoryProcessor::Process(std::vector<std::string> input)
	{
		std::vector<ValueHistory> valueHistories;

		for (const auto& line : input)
		{
			std::istringstream iss(line);

			ValueHistory history;
			int64_t val;
			while (iss >> val)
				history.Values.emplace_back(val);

			valueHistories.emplace_back(history);
		}

		return valueHistories;
	}
}
