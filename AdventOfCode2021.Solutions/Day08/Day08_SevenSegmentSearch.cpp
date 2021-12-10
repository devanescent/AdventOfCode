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
					[](const SignalPattern& digit)
					{
						// Count occurances of digits '1' (len 2), '4' (len 4), '7' (len 3) and '8' (len 7)
						// (= digits with patterns of unique length):
						switch (digit.size())
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
		for (SignalPatternObservation& obs : patterns)
		{
			// Mappings for patterns to digits:
			std::map<SignalPattern, int> patternToDigit;

			// Get these three patterns for later deductions:
			SignalPattern digit1Pattern = obs.FindPatternByLen(2);
			SignalPattern digit7Pattern = obs.FindPatternByLen(3);
			SignalPattern digit4Pattern = obs.FindPatternByLen(4);

			// First, add patterns of unique lengths:
			patternToDigit[digit1Pattern] = 1;
			patternToDigit[digit7Pattern] = 7;
			patternToDigit[digit4Pattern] = 4;
			patternToDigit[obs.FindPatternByLen(7)] = 8;

			// Then, find other patterns by the following deductions:

			// '6': The only len-6 pattern that does NOT contain the pattern for digit '1':
			SignalPattern digit6Pattern = obs.FindPatternByLenAndSubPattern(6, digit1Pattern, false, false);
			patternToDigit[digit6Pattern] = 6;

			// '9' The only len-6 pattern that DOES contain the pattern for digit '4':
			SignalPattern digit9Pattern = obs.FindPatternByLenAndSubPattern(6, digit4Pattern, true, false);
			patternToDigit[digit9Pattern] = 9;

			// '3': The only len-5 pattern that DOES contain the pattern for digit '1':
			SignalPattern digit3Pattern = obs.FindPatternByLenAndSubPattern(5, digit1Pattern, true, false);
			patternToDigit[digit3Pattern] = 3;

			// '5': The only len-5 pattern that is contained in the pattern for digit '6':
			SignalPattern digit5Pattern = obs.FindPatternByLenAndSubPattern(5, digit6Pattern, true, true);
			patternToDigit[digit5Pattern] = 5;

			// '0': By exclusion of the previously found len-6 patterns:
			SignalPattern digit0Pattern = obs.FindPatternByExclusion(6, digit6Pattern, digit9Pattern);
			patternToDigit[digit0Pattern] = 0;

			// '2': By exclusion of the previously found len-5 patterns:
			SignalPattern digit2Pattern = obs.FindPatternByExclusion(5, digit3Pattern, digit5Pattern);
			patternToDigit[digit2Pattern] = 2;

			// Calculate the displayed number:
			int resultingNumber = 0;
			for (int i = 0, f = 1000; i < 4; ++i, f /= 10)
			{
				resultingNumber += patternToDigit[obs.DisplayedDigits[i]] * f;
			}
		}	

		return 0ull;
	}
}
