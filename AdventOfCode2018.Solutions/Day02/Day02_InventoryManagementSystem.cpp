#include "Day02_InventoryManagementSystem.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day02
{
	InventoryManagementSystem::InventoryManagementSystem() : Day(2, "Inventory Management System")
	{}

	uint64_t Day02::InventoryManagementSystem::GetResultOnPart1(const std::vector<std::string> input)
	{
		uint64_t twoLettersCount = 0, threeLettersCount = 0;

		for (std::string boxId : input)
		{
			bool hasTwoEqualLetters = false, hasThreeEqualLetters = false;

			// Sort so that equal letters are adjacent to each other
			std::sort(boxId.begin(), boxId.end());
			auto eqRangeStart = boxId.begin();
			do
			{
				// Find the end of a block of equal letters:
				auto eqRangeEnd = std::upper_bound(eqRangeStart, boxId.end(), *eqRangeStart);

				// Get this block's length:
				auto eqRangeLen = std::distance(eqRangeStart, eqRangeEnd);

				// Increment the corresponding counters:
				if (!hasTwoEqualLetters && eqRangeLen == 2)
				{
					hasTwoEqualLetters = true;
					twoLettersCount++;
				}
				else if (!hasThreeEqualLetters && eqRangeLen == 3)
				{
					hasThreeEqualLetters = true;
					threeLettersCount++;
				}
				
				// Each counter can only be incremented once, so skip the rest of the letters in that case:
				if (hasTwoEqualLetters && hasThreeEqualLetters)
					break;

				// Otherwise, continue with the next block:
				eqRangeStart = eqRangeEnd;

			} while (eqRangeStart != boxId.end());
		}

		// Calculate checksum:
		return twoLettersCount * threeLettersCount;
	}
}
