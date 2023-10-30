#include "Day02_InventoryManagementSystem.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day02
{
	InventoryManagementSystem::InventoryManagementSystem() : Day(2, "Inventory Management System")
	{}

	uint64_t InventoryManagementSystem::ExecutePart1(const std::vector<std::string> input)
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

	std::string InventoryManagementSystem::ExecutePart2(const std::vector<std::string> input)
	{
		for (auto id1 = input.begin() + 1; id1 != input.end(); ++id1)
		{
			for (auto id2 = input.begin(); id2 != id1; ++id2)
			{
				int numberOfDiffs = 0;
				int firstDiffIndex = 0;

				for (int i = 0; i < id1->length(); ++i)
				{
					if ((*id1)[i] != (*id2)[i])
					{
						numberOfDiffs++;
						firstDiffIndex = i;
					}

					if (numberOfDiffs > 1)
						break;
				}

				if (numberOfDiffs == 1)
				{
					std::string result = *id1;
					result.erase(firstDiffIndex, 1);
					return result;
				}
			}
		}
	}
}
