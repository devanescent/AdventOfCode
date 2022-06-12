#include "GuardDutyRecordProcessor.h"
#include <algorithm>
#include <regex>

namespace AdventOfCode::Year2018::Day04
{
	// Parses the data into the record fields
	std::unique_ptr<GuardDutyRecord> ParseRecord(const std::string& claimData)
	{
		std::regex claimPattern = std::regex("([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2})\\] (Guard|falls|wakes) (?:#([0-9]+))?");

		// Number of matches == 8: the whole string plus all 6/7 (with guard number) capture groups:
		std::smatch matches;
		if (std::regex_search(claimData, matches, claimPattern))
		{
			if (matches[7].matched)
			{
				return std::make_unique<BeginShiftRecord>(
					atoi(matches[1].str().c_str()),
					atoi(matches[2].str().c_str()),
					atoi(matches[3].str().c_str()),
					atoi(matches[4].str().c_str()),
					atoi(matches[5].str().c_str()),
					atoi(matches[7].str().c_str())
				);
			}
			else
			{
				return std::make_unique<SleepRecord>(
					atoi(matches[1].str().c_str()),
					atoi(matches[2].str().c_str()),
					atoi(matches[3].str().c_str()),
					atoi(matches[4].str().c_str()),
					atoi(matches[5].str().c_str()),
					matches[6].str() == "falls"
				);
			}
		}
		
		throw std::exception();
	}

	std::vector<std::unique_ptr<GuardDutyRecord>> GuardDutyRecordProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::unique_ptr<GuardDutyRecord>> records;
		std::transform(input.begin(), input.end(), std::back_inserter(records), ParseRecord);
		return records;
	}
}
