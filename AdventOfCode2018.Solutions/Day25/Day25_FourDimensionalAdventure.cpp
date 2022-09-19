#include "Day25_FourDimensionalAdventure.h"

namespace AdventOfCode::Year2018::Day25
{
	FourDimensionalAdventure::FourDimensionalAdventure() : DayT(25, "Four-Dimensional Adventure") {}


	uint64_t FourDimensionalAdventure::ExecutePart1(std::vector<SpacetimeFixpoint> fixPoints)
	{
		std::vector<Constellation> constellations;

		for (const SpacetimeFixpoint& fp : fixPoints)
		{
			// Find first constellation to add to:
			auto firstJoinableConst = std::find_if(constellations.begin(), constellations.end(),
				[fp](const Constellation& c) { return c.TryAddPoint(fp); }
			);

			if (firstJoinableConst == constellations.end())
			{
				// Point cannot be connected to any other constellelation: create a new constellation one:
				constellations.emplace_back(fp);
			}
			else
			{
				// Add point to this constellation:
				firstJoinableConst->AddPoint(fp);

				// Are there other constellations? If there are, they must be merged into the first one:
				// Search from the end, because the joined constellations have to be removed from the collection:
				auto constIt = constellations.end() - 1;
				while (constIt != firstJoinableConst)
				{
					if (constIt->TryAddPoint(fp))
					{
						firstJoinableConst->Join(*constIt);
						constIt = constellations.erase(constIt); // erase only invalidates iterators to elements at and after the erase
					}

					--constIt;
				}
			}
		}

		return constellations.size();
	}
}