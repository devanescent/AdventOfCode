#include "ReportsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day02
{
	std::vector<Report> ReportsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Report> reports;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			reports.emplace_back(std::vector(std::istream_iterator<int>(iss), std::istream_iterator<int>()));
		}

		return reports;
	}
}
