#include "Day05_BinaryBoarding.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day05
{
	BinaryBoarding::BinaryBoarding() : DayT(5, "Binary Boarding") {}

	uint64_t BinaryBoarding::ExecutePart1(std::vector<int> seatIDs)
	{
		return *(std::max_element(seatIDs.begin(), seatIDs.end()));
	}

	uint64_t BinaryBoarding::ExecutePart2(std::vector<int> seatIDs)
	{
		std::sort(seatIDs.begin(), seatIDs.end());
		auto result = std::adjacent_find(seatIDs.begin(), seatIDs.end(),
			[](const int& id1, const int& id2)
			{
				// Find the gap in the list of seat ids:
				return id2 != id1 + 1;
			}
		);

		return static_cast<uint64_t>(*result) + 1;
	}
}
