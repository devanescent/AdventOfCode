#include "Day09_EncodingError.h"
#include "Utils.h"

namespace AdventOfCode::Year2020::Day09
{ 
	Day09::EncodingError::EncodingError(int preambleLen): DayT(9, "Encoding Error"), 
		m_preambleLen(preambleLen)
	{ }

	uint64_t Day09::EncodingError::ExecutePart1(std::vector<int> input)
	{
		if ((int)input.size() > m_preambleLen)
		{
			for (auto it = input.begin() + m_preambleLen; it != input.end(); ++it)
			{
				std::vector<int> preamble(it - m_preambleLen, it);

				if (!FindPairForGivenSum(preamble, *it))
					return *it;
			}
		}

		return 0;
	}
}