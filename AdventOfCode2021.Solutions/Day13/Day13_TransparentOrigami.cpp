#include "Day13_TransparentOrigami.h"
#include <algorithm>
#include <numeric>
#include <functional>

namespace AdventOfCode::Year2021::Day13
{
	TransparentOrigami::TransparentOrigami() : DayTC(13, "Transparent Origami") {}

	uint64_t TransparentOrigami::ExecutePart1(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper)
	{
		// Expecting: folding is always by half, so the paper always perfectly overlaps

		// First fold:
		const FoldInstruction& foldInstr = foldInstrs[0];

		if (foldInstr.Direction == FoldDirection::Horizontal)
		{
			// For each row: merge the (reversed) second half (to the right of the fold) into the first half
			for (auto& row : paper)
			{
				auto foldIt = row.begin() + foldInstr.Position;
				std::transform(
					row.begin(), foldIt,	// left half
					row.rbegin(),			// second half (reversed)
					row.begin(),			// destination: left half
					std::logical_or<>()
				);

				// Remove right half (including the fold):
				row.erase(foldIt, row.end());
			}
		}
		else
		{
			// For each row below the fold: merge into the corresponding row above:
			auto foldIt = paper.begin() + foldInstr.Position;
			for (int i = 1; i < (paper.size() - foldInstr.Position); ++i)
			{
				std::transform(
					(foldIt + i)->begin(), (foldIt + i)->end(),	// row below the fold
					(foldIt - i)->begin(),						// row above the fold
					(foldIt - i)->begin(),						// destination: top row
					std::logical_or<>()
				);
			}

			// Remove bottom rows (including the fold):
			paper.erase(foldIt, paper.end());
		}

		// Count number of dots (fields where value is true):
		return std::accumulate(paper.begin(), paper.end(), 0ull,
			[](uint64_t count, const auto& row)
			{
				return count + std::count(row.begin(), row.end(), true);
			}
		);
	}
}


