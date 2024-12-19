#include "TowelPatternProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day19
{
	std::pair<std::vector<DisplayDesign>, TowelPatterns> TowelPatternProcessor::Process(std::vector<std::string> input)
	{
		// First line contains available towel patterns:
		TowelPatterns towelPatterns;

		std::istringstream iss(input[0]);
		std::string towelPattern;
		
		while (std::getline(iss, towelPattern, ','))
		{
			if (towelPattern[0] == ' ')
				towelPattern.erase(towelPattern.begin());
			towelPatterns.AddPattern(towelPattern);
		}
		
		// The rest of the lines contain display designs, separated by a blank line:
		std::vector<DisplayDesign> displayDesigns;
		for (int i = 2; i < input.size(); ++i)
		{
			displayDesigns.push_back(input[i]);
		}

		return std::make_pair(displayDesigns, towelPatterns);
	}
}
