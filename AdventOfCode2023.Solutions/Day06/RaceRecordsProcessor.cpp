#include "RaceRecordsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day06
{
	std::vector<RaceRecord> RaceRecordsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RaceRecord> raceRecords;

		std::istringstream issTime(input[0]);
		std::istringstream issDistance(input[1]);

		std::string ignore;
		issTime >> ignore;
		issDistance >> ignore;

		int time, distance;
		while (issTime >> time && issDistance >> distance)
		{
			raceRecords.emplace_back(time, distance);
		}

		return raceRecords;
	}
}
