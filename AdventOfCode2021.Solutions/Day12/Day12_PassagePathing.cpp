#include "Day12_PassagePathing.h"


namespace AdventOfCode::Year2021::Day12
{
	PassagePathing::PassagePathing() : DayT(12, "Passage Pathing") {}

	uint64_t PassagePathing::ExecutePart1(std::vector<CaveConnection> connections)
	{
		// Build map of all caves:
		CaveMap caveMap;

		for (const auto& con : connections)
		{
			// both directions:
			caveMap[con.Cave1].push_back(con.Cave2);
			caveMap[con.Cave2].push_back(con.Cave1);
		}

		// All paths:
		std::vector<std::string> pathSoFar{ "start" };
		return VisitCaves(caveMap, "start", pathSoFar);
	}

	uint64_t PassagePathing::VisitCaves(CaveMap& map, std::string currentCave, std::vector<std::string>& pathSoFar)
	{
		uint64_t numberOfPaths = 0;

		if (currentCave != "end")
		{
			const std::vector<std::string>& availablePaths = map[currentCave];
			for (const auto& nextCave : availablePaths)
			{
				if (nextCave[0] >= 'A' && nextCave[0] <= 'Z' || // large cave: can always be visited
					std::find(pathSoFar.rbegin(), pathSoFar.rend(), nextCave) == pathSoFar.rend()) // otherwise small cave: check if not yet visited
				{
					pathSoFar.push_back(nextCave);
					numberOfPaths += VisitCaves(map, nextCave, pathSoFar);
				}
			}
		}
		else
			++numberOfPaths;

		// all paths explored:
		pathSoFar.pop_back();
		return numberOfPaths;
	}
}


