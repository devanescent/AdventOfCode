#include "SignalPatternProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2021::Day08
{
	std::vector<SignalPatternObservation> SignalPatternProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SignalPatternObservation> patternResults;

		for (const std::string& noteEntry : input)
		{
			std::istringstream iss(noteEntry);
			SignalPatternObservation sigPatterns;

			// Patterns for all 10 digits:
			for (int i = 0; i < 10; ++i)
			{
				iss >> sigPatterns.UniquePatterns[i];
				std::sort(sigPatterns.UniquePatterns[i].begin(), sigPatterns.UniquePatterns[i].end());
			}

			// Discard separator:
			char separator;
			iss >> separator;

			// Displayed digits (4 digit displays):
			for (int i = 0; i < 4; ++i)
			{
				iss >> sigPatterns.DisplayedDigits[i];
				std::sort(sigPatterns.DisplayedDigits[i].begin(), sigPatterns.DisplayedDigits[i].end());
			}

			// Add pattern:
			patternResults.push_back(sigPatterns);
		}

		return patternResults;
	}
}

