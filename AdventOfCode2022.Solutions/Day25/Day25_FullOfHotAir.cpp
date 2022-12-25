#include "Day25_FullOfHotAir.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2022::Day25
{
	FullOfHotAir::FullOfHotAir() : DayT(25, "Full of Hot Air") { }

	uint64_t FullOfHotAir::ExecutePart1(std::vector<SNAFUNumber> numbers)
	{
		uint64_t sum = std::accumulate(numbers.begin(), numbers.end(), 0ull,
			[](uint64_t total, const SNAFUNumber& n)
			{
				return total += n.Value();
			}
		);

		// To convert back into a SNAFU number, find maximum power of five needed:
		uint64_t currentMaxNum = 0;
		uint64_t pMax = 0;

		for (uint64_t power = 1;; power *= 5)
		{
			currentMaxNum += power * 2; // maximum value that can be reached by this power of five
			if (currentMaxNum >= sum)
			{
				pMax = power;
				break;
			}
		}

		// Convert back into SNAFU number:
		std::string snafuStr;
		std::vector<int> factors{ +2, +1, 0, -1, -2 };

		int64_t remainingValue = sum;
		for (int64_t p = pMax; p > 0; p /= 5)
		{
			// Closest factor to the remining value:
			int f = *std::min_element(factors.begin(), factors.end(),
				[&remainingValue, &p](int f1, int f2)
				{ return std::abs(p * f1 - remainingValue) < std::abs(p * f2 - remainingValue); }
			);

			// Append SNAFU number:
			switch (f)
			{
				case -2: snafuStr += '='; break;
				case -1: snafuStr += '-'; break;
				case  0: snafuStr += '0'; break;
				case +1: snafuStr += '1'; break;
				case +2: snafuStr += '2'; break;
			}

			remainingValue -= p * f;
		}

		// Return numeric value for tests:
		return sum;
	}

	uint64_t FullOfHotAir::ExecutePart2(std::vector<SNAFUNumber> numbers)
	{
		return uint64_t();
	}
}
