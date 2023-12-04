#pragma once
#include <algorithm>
#include <set>

namespace AdventOfCode::Year2023::Day04
{
	class Scratchcard
	{
	public:
		std::set<int> WinningNumbers;
		std::set<int> Numbers;

		int CountMatches() const
		{
			std::vector<int> matchingNums;

			std::set_intersection(
				Numbers.begin(), Numbers.end(),
				WinningNumbers.begin(), WinningNumbers.end(),
				std::back_inserter(matchingNums));

			return matchingNums.size();
		}

		int Copies = 1;
	};
}
