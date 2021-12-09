#include "Day08_SevenSegmentSearch.h"
#include <algorithm>
#include <numeric>
#include <map>

namespace AdventOfCode::Year2021::Day08
{
	SevenSegmentSearch::SevenSegmentSearch() : DayT(8, "Seven Segment Search") {}

	uint64_t SevenSegmentSearch::ExecutePart1(std::vector<SignalPatternObservation> patterns)
	{
		// Count number of unique displayed digits in each pattern, sum all counts together:
		return std::accumulate(patterns.begin(), patterns.end(), 0ull,
			[](uint64_t totalSum, const SignalPatternObservation& observedPattern)
			{
				return totalSum + std::count_if(observedPattern.DisplayedDigits.begin(), observedPattern.DisplayedDigits.end(),
					[](const std::string& obsPat)
					{
						// Count occurances of digits '1' (len 2), '4' (len 4), '7' (len 3) and '8' (len 7)
						// (= digits with patterns of unique length):
						switch (obsPat.length())
						{
						case 2: case 3: case 4: case 7:
							return true;
						default:
							return false;
						}
					}
				);
			}
		);
	}

	uint64_t SevenSegmentSearch::ExecutePart2(std::vector<SignalPatternObservation> patterns)
	{
		//for (const SignalPatternObservation& obs : patterns)
		//{
		//	// Mappings for patterns to digits:
		//	std::map<std::string, int> patternToDigit;

		//	// Predicate for finding a pattern with given length:
		//	auto withLen = [](int len) { return [len](const std::string& pattern) { return pattern.length() == len; }; };

		//	// Get these three patterns for later deductions:
		//	const std::string& digit1Pattern = obs.FindPattern(withLen(2)).value();
		//	const std::string& digit7Pattern = obs.FindPattern(withLen(3)).value();
		//	const std::string& digit4Pattern = obs.FindPattern(withLen(4)).value();

		//	// First, add patterns of unique lengths:
		//	patternToDigit[digit1Pattern] = 1;
		//	patternToDigit[digit7Pattern] = 7;
		//	patternToDigit[digit4Pattern] = 4;
		//	patternToDigit[obs.FindPattern([](const std::string& pattern) { return pattern.length() == 7; }).value()] = 8;

		//	// Then, find other patterns by the following deductions:
		//	// '9': The only len-6 pattern that does not contain the pattern for digit '1':
		//	patternToDigit[obs.FindPattern([&digit1Pattern](const std::string& pattern) { return pattern.length() == 6; }).value()] = 9;


		//	int resultingNumber = 0;
		//	for (int i = 0, f = 1000; i < 4; ++i, f /= 10)
		//	{
		//		resultingNumber += patternToDigit[obs.DisplayedDigits[i]] * f;
		//	}
		//}	

		return 0ull;
	}
}
