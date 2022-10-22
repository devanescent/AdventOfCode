#include "Day24_LobbyLayout.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2020::Day24
{
	LobbyLayout::LobbyLayout() : DayT(24, "Lobby Layout")
	{}

	enum class TileState
	{
		White,
		Black
	};

	struct TileData
	{
		TileState State;
		int BlackNeighbours;

		TileData() : State(TileState::White), BlackNeighbours(0) {}
		TileData(TileState state, int neighbours) : State(state), BlackNeighbours(neighbours) {}
	};

	uint64_t LobbyLayout::ExecutePart1(std::vector<HexCoords> coordsList)
	{
		std::map<HexCoords, TileState> allCoords;

		for (const HexCoords& coords : coordsList)
		{
			auto it = allCoords.find(coords);
			if (it != allCoords.end())
			{
				// already there: flip tile
				it->second = it->second == TileState::Black ? TileState::White : TileState::Black;
			}
			else
				allCoords[coords] = TileState::Black;	// first time: set to black
		}

		return std::count_if(allCoords.begin(), allCoords.end(), [](auto& kv) { return kv.second == TileState::Black; });
	}

	uint64_t LobbyLayout::ExecutePart2(std::vector<HexCoords> coordsList)
	{
		std::map<HexCoords, TileData> allCoords;

		// Initial configuration (same as part 1):
		for (const HexCoords& coords : coordsList)
		{
			auto it = allCoords.find(coords);
			if (it != allCoords.end())
			{
				// already there: flip tile
				it->second.State = it->second.State == TileState::Black ? TileState::White : TileState::Black;
			}
			else
				allCoords[coords].State = TileState::Black;	// first time: set to black
		}

		for (int day = 0; day < 100; ++day)
		{
			std::map<HexCoords, TileData> nextDay;

			// For each black tile, update count of all their neighbour
			for (const auto& coords : allCoords)
			{
				if (coords.second.State == TileState::Black)
				{
					// Update neighbours:
					for (auto&& neighbour : coords.first.GetNeighbours())
					{
						auto neighbourTile = nextDay.find(neighbour);
						if (neighbourTile == nextDay.end())
							nextDay.emplace(neighbour, TileData(TileState::White, 1 ));
						else
							++neighbourTile->second.BlackNeighbours;
					}

					// Insert / update itself for the next day:
					auto self = nextDay.find(coords.first);
					if (self == nextDay.end())
						nextDay.emplace(coords.first, TileData(TileState::Black, 0));
					else
						self->second.State = TileState::Black;
				}
			}

			// Update black tiles based on the rules:
			for (auto& nextCoords : nextDay)
			{
				// Black tiles: Flipped to white if either zero black neighbours or more than two:
				if (nextCoords.second.State == TileState::Black && 
					(nextCoords.second.BlackNeighbours == 0 || nextCoords.second.BlackNeighbours > 2))
				{
					nextCoords.second.State = TileState::White;
				}
				// White tiles: Flipped to black if exactly two black neighbours:
				else if (nextCoords.second.State == TileState::White && nextCoords.second.BlackNeighbours == 2)
				{
					nextCoords.second.State = TileState::Black;
				}

				// Reset neighbour counter:
				nextCoords.second.BlackNeighbours = 0;
			}

			allCoords = std::move(nextDay);
		}

		return std::count_if(allCoords.begin(), allCoords.end(), [](auto& kv) { return kv.second.State == TileState::Black; });
	}
}
