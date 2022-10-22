#include "Day20_JurassicJigsaw.h"
#include <map>

namespace AdventOfCode::Year2020::Day20
{
	JurassicJigsaw::JurassicJigsaw() : DayT(20, "Jurassic Jigsaw")
	{}

	uint64_t JurassicJigsaw::ExecutePart1(std::vector<Tile> tiles)
	{
		uint64_t result = 1;

		// Count number of matches for each tile: the relevant corner tiles can be identified as the tiles having only two matches
		std::map<int /*Tile-ID*/, int> matchCounts;

		for (auto t1 = tiles.begin(); t1 != tiles.end(); ++t1)
		{
			for (auto t2 = t1 + 1; t2 != tiles.end(); ++t2)
			{
				if (t1->Match(*t2))
				{
					if (matchCounts.find(t1->GetID()) == matchCounts.end())
						matchCounts[t1->GetID()] = 1;
					else
						++matchCounts[t1->GetID()];

					if (matchCounts.find(t2->GetID()) == matchCounts.end())
						matchCounts[t2->GetID()] = 1;
					else
						++matchCounts[t2->GetID()];
				}
			}
		}

		// Get product of ids of all corner tiles:
		for (auto& mc : matchCounts)
		{
			if (mc.second == 2)
				result *= mc.first;
		}

		return result;
	}
}
