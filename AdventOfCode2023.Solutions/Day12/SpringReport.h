#pragma once
#include <map>
#include <string>
#include <vector>

namespace AdventOfCode::Year2023::Day12
{
	class SpringReport
	{
	public:
		std::string Conditions;
		std::vector<int> DamageGroups;

		uint64_t CountArrangements()
		{
			std::vector<int> groupOffsets(DamageGroups.size(), 0);
			return ArrangeGroups(groupOffsets, 0);
		}

		// Key: Grp-Index + Offset; Value: valid arrangements
		std::map<std::pair<int, int>, uint64_t> m_cache;

	private:
		uint64_t ArrangeGroups(std::vector<int> grpOffsets, int currentGrpIndex)
		{
			if (currentGrpIndex == DamageGroups.size())
			{
				// All groups fitted within the record
				// -> check that no unmatched '#' are behind the last group:
				for (int i = grpOffsets[currentGrpIndex - 1] + DamageGroups[currentGrpIndex - 1]; i < Conditions.size(); ++i)
				{
					if (Conditions[i] == '#')
						return 0;
				}

				// otherwise this i a valid configuration:
				return 1;
			}

			// Count arrangements for each possible position of this group:
			uint64_t currentArrangementCount = 0;

			// Start offset of this group:
			// 0 if first group, else behind previous group (+1 for space between groups)
			int startOffset = currentGrpIndex == 0 ? 0 : grpOffsets[currentGrpIndex - 1] + DamageGroups[currentGrpIndex - 1] + 1;

			for (int currentOffset = startOffset; currentOffset < Conditions.size(); ++currentOffset)
			{
				grpOffsets[currentGrpIndex] = currentOffset;

				auto cachedVal = m_cache.find(std::make_pair(currentGrpIndex, currentOffset));
				if (cachedVal != m_cache.end())
				{
					currentArrangementCount += cachedVal->second;
				}
				else
				{
					// no cached data for this group at this position: check if it fits at its current position:
					if (currentOffset > 0)
					{
						// If there is an unmatched block character in front of the current block,
						// this configuration can never be valid again, so end this iteration:
						if (Conditions[currentOffset - 1] == '#')
							break;
					}

					bool fits = true;

					// Check across the length of the block: there must be no empty ('.') spaces within
					// and the block must fit within the record
					for (int x = currentOffset; x < currentOffset + DamageGroups[currentGrpIndex]; ++x)
					{
						if (x >= Conditions.size() || Conditions[x] == '.')
							fits = false;
					}

					// If there is still space behind, it must not be another block 
					// (blocks must be separated by at least one empty space)
					if (fits && currentOffset + DamageGroups[currentGrpIndex] <= Conditions.size() - 1)
						if (Conditions[currentOffset + DamageGroups[currentGrpIndex]] == '#')
							fits = false;


					if (fits)
					{
						// Continue with next group:
						auto arrangements = ArrangeGroups(grpOffsets, currentGrpIndex + 1);
						currentArrangementCount += arrangements;

						m_cache[std::make_pair(currentGrpIndex, currentOffset)] = arrangements;
					}
				}
			}

			return currentArrangementCount;
		}
	};
}
