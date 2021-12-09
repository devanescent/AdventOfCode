#include "Day20_JurassicJigsaw.h"
#include <map>

namespace AdventOfCode::Year2020::Day20
{
	JurassicJigsaw::JurassicJigsaw() : DayT(20, "Jurassic Jigsaw")
	{}

	uint64_t JurassicJigsaw::ExecutePart1(std::vector<Tile> input)
	{
		uint64_t result = 1;

		if (!input.empty())
		{
			// Count number of matches for each tile: the relevant corner tiles can be identified as the tiles having only two matches
			std::map<Tile*, int> matchCounts;

			for (auto t1 = input.begin(); t1 != input.end(); ++t1)
			{
				for (auto t2 = t1 + 1; t2 != input.end(); ++t2)
				{
					if (t1->Match(t2._Ptr))
					{
						if (matchCounts.find(t1._Ptr) == matchCounts.end())
							matchCounts[t1._Ptr] = 1;
						else
							++matchCounts[t1._Ptr];

						if (matchCounts.find(t2._Ptr) == matchCounts.end())
							matchCounts[t2._Ptr] = 1;
						else
							++matchCounts[t2._Ptr];
					}
				}
			}

			for (auto& mc : matchCounts)
			{
				// Get product of ids of all corner tiles:
				if (mc.second == 2)
					result *= mc.first->GetID();
			}
		}

		return result;
	}
}
