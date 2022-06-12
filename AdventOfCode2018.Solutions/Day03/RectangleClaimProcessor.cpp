#include "RectangleClaimProcessor.h"
#include <algorithm>
#include <regex>

namespace AdventOfCode::Year2018::Day03
{
	// Parses the data into the passport fields
	RectangleClaim ParseClaim(const std::string& claimData)
	{
		std::regex claimPattern = std::regex("#([0-9]+) @ ([0-9]+),([0-9]+): ([0-9]+)x([0-9]+)");

		// Number of matches == 6: the whole string plus all 5 capture groups
		std::smatch matches;
		if (std::regex_search(claimData, matches, claimPattern) && matches.size() == 6)
		{
			return RectangleClaim(
				atoi(matches[1].str().c_str()),
				atoi(matches[2].str().c_str()),
				atoi(matches[3].str().c_str()),
				atoi(matches[4].str().c_str()),
				atoi(matches[5].str().c_str())
			);
		}
		else
			throw std::exception();
	}

	// Each passport is represented as a sequence of key:value pairs separated by
	// spaces or newlines. Passports are separated by blank lines.
	std::vector<RectangleClaim> RectangleClaimProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RectangleClaim> claims;
		std::transform(input.begin(), input.end(), std::back_inserter(claims), ParseClaim);
		return claims;
	}
}
