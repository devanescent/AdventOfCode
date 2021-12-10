#pragma once
#include <array>
#include <set>
#include <algorithm>

namespace AdventOfCode::Year2021::Day08
{
	using SignalPattern = std::set<char>;

	class SignalPatternObservation
	{
	public:
		std::array<SignalPattern, 10>	UniquePatterns;		// 10 observed patterns for digits
		std::array<SignalPattern, 4>	DisplayedDigits;	// Digits that are actually displayed

		// Find a specific pattern by length (only works for unique lengths):
		SignalPattern FindPatternByLen(int len) const
		{
			return *std::find_if(UniquePatterns.begin(), UniquePatterns.end(), 
				[len](const SignalPattern& pattern) { return pattern.size() == len; }
			);
		}

		/// <summary>
		/// Find a specific digit pattern by length and a subpattern
		/// </summary>
		/// <param name="len">- Len of the matching pattern</param>
		/// <param name="subPattern">- subpattern to be checked</param>
		/// <param name="shallContain">- If true, check if the subpattern is contained in the pattern, else if it is NOT contained</param>
		/// <param name="swapPatterns">- If true, swap pattern and subpattern</param>
		/// <returns></returns>
		SignalPattern FindPatternByLenAndSubPattern(int len, const SignalPattern& subPattern, bool shallContain, bool swapPatterns) const
		{
			return *std::find_if(UniquePatterns.begin(), UniquePatterns.end(),
				[len, &subPattern, shallContain, swapPatterns](const SignalPattern& pattern)
				{ 
					bool matchesLen = (pattern.size() == len);
					if (!matchesLen) return false;

					bool includesSubPattern = swapPatterns ?
						std::includes(subPattern.begin(), subPattern.end(), pattern.begin(), pattern.end()) :
						std::includes(pattern.begin(), pattern.end(), subPattern.begin(), subPattern.end());

					return shallContain ? includesSubPattern : !includesSubPattern;
					
				}
			);
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="len"></param>
		/// <param name="pattern1"></param>
		/// <param name="pattern2"></param>
		/// <returns></returns>
		SignalPattern FindPatternByExclusion(int len, const SignalPattern& pattern1, const SignalPattern& pattern2)
		{
			return *std::find_if(UniquePatterns.begin(), UniquePatterns.end(),
				[len, &pattern1, &pattern2](const SignalPattern& pattern) 
				{ 
					return pattern.size() == len && pattern != pattern1 && pattern != pattern2;
				}
			);
		}
	};
}