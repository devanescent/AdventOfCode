#include "Day24_LobbyLayout.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2020::Day24
{
	LobbyLayout::LobbyLayout() : DayT(24, "Lobby Layout")
	{}

	uint64_t LobbyLayout::ExecutePart1(std::vector<HexCoords> coordsList)
	{
		std::map<HexCoords, bool> allCoords;

		for (const HexCoords& coords : coordsList)
		{
			auto it = allCoords.find(coords);
			if (it != allCoords.end())
				it->second = !it->second;	// already there: toggle flip state
			else
				allCoords[coords] = true;	// first time: flip tile
		}

		return std::count_if(allCoords.begin(), allCoords.end(), [](auto& kv) { return kv.second; });
	}
}
