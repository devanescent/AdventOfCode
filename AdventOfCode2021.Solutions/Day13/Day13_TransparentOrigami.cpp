#include "Day13_TransparentOrigami.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>

namespace AdventOfCode::Year2021::Day13
{
	TransparentOrigami::TransparentOrigami() : DayTC(13, "Transparent Origami") {}

	uint64_t TransparentOrigami::ExecutePart1(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper)
	{
		// Apply first fold:
		FoldPaper(paper, foldInstrs[0]);

		// Count number of dots (fields where value is true):
		return std::accumulate(paper.begin(), paper.end(), 0ull,
			[](uint64_t count, const auto& row)
			{
				return count + std::count(row.begin(), row.end(), true);
			}
		);
	}

	uint64_t TransparentOrigami::ExecutePart2(std::vector<FoldInstruction> foldInstrs, OrigamiPaper paper)
	{
		for (const auto& foldInstr : foldInstrs)
			FoldPaper(paper, foldInstr);

		PrintResult(paper);
		return 0ull;  // result can be read from console window
	}

	// Apply the given fold instruction to the paper:
	void TransparentOrigami::FoldPaper(OrigamiPaper& paper, const FoldInstruction& foldInstr)
	{
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
	}

	// Print the folded paper to read the letters:
	void TransparentOrigami::PrintResult(OrigamiPaper& foldedPaper)
	{
		for (const auto& row : foldedPaper)
		{
			std::vector<char> cString;
			std::transform(row.begin(), row.end(), std::back_inserter(cString), [](bool b) {return b ? '#' : '.'; });
			std::cout << std::string(cString.begin(), cString.end()) << "\n";
		}
	}
}


