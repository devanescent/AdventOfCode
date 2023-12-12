#include "SpringReportProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day12
{
	std::vector<SpringReport> SpringReportProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SpringReport> springReports;

		for (const auto& line : input)
		{
			std::istringstream iss(line);

			SpringReport report;
			iss >> report.Conditions;

			std::string grp;
			while (std::getline(iss, grp, ','))
				report.DamageGroups.emplace_back(std::stoi(grp));

			springReports.emplace_back(report);
		}

		return springReports;
	}
}
