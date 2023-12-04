#include "Day04_Scratchcards.h"
#include <algorithm>
#include <numeric>
#include <unordered_set>

namespace AdventOfCode::Year2023::Day04
{
	Scratchcards::Scratchcards() : DayT(4, "Scratchcards") { }

	uint64_t Scratchcards::ExecutePart1(std::vector<Scratchcard> scratchcards)
	{
		return std::accumulate(scratchcards.begin(), scratchcards.end(), 0ull,
			[](uint64_t totalPoints, const Scratchcard& sc)
			{
				int matches = sc.CountMatches();
				if (matches > 0)
				{
					// First match: 1 point
					uint64_t points = 1;

					// Each more match doubles points:
					for (int i = 1; i < matches; ++i)
						points *= 2;
					return totalPoints + points;
				}
				else
					return totalPoints;
			});
	}

	uint64_t Scratchcards::ExecutePart2(std::vector<Scratchcard> scratchcards)
	{
		for (int i = 0; i < scratchcards.size(); ++i)
		{
			Scratchcard& sc = scratchcards[i];
			int matches = sc.CountMatches();

			for (int m = 0; m < matches; ++m)
			{
				// Add copies of following cards:
				scratchcards[i + m + 1].Copies += sc.Copies;
			}
		}

		return std::accumulate(scratchcards.begin(), scratchcards.end(), 0ull,
			[](uint64_t totalCopies, const Scratchcard& sc)
			{
				return totalCopies + sc.Copies;
			});
	}
}
