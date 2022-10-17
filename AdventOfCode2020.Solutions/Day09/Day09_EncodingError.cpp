#include "Day09_EncodingError.h"
#include "Utils.h"

#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2020::Day09
{ 
	Day09::EncodingError::EncodingError(size_t preambleLen) : DayT(9, "Encoding Error"),
		m_preambleLen(preambleLen) { }

	uint64_t Day09::EncodingError::ExecutePart1(std::vector<uint64_t> input)
	{
		// Start processing numbers after preamble:
		for (auto numIt = input.begin() + m_preambleLen; numIt != input.end(); ++numIt)
		{
			// Find pair in preamble (i.e. previous 25 numbers):
			auto findPair = [&]()
			{
				for (auto preambleIt1 = numIt - m_preambleLen; preambleIt1 != numIt; ++preambleIt1)
				{
					for (auto preambleIt2 = preambleIt1 + 1; preambleIt2 != numIt; ++preambleIt2)
					{
						if (*preambleIt1 + *preambleIt2 == *numIt) 
							return true;
					}
				}
				return false;
			};

			// If no such pair was found, return the number:
			if (!findPair())
				return *numIt;
		}

		return 0ull;
	}

	uint64_t Day09::EncodingError::ExecutePart2(std::vector<uint64_t> input)
	{
		// Get invalid number from part 1:
		auto invalNum = ExecutePart1(input);

		//
		auto it1 = input.begin(), it2 = input.begin() + 2;

		while (it2 != input.end())
		{
			uint64_t contSum = std::accumulate(it1, it2, 0ull);
			if (contSum < invalNum)
				++it2;
			else if (contSum > invalNum)
				++it1;
			else
			{
				// Find smallest and largest number in range and add them up:
				auto minmaxPair = std::minmax_element(it1, it2);
				return *minmaxPair.first + *minmaxPair.second;
			}
		}

		return 0;
	}
}