#include "Day11_HexEd.h"
#include <map>
#include <numeric>

namespace AdventOfCode::Year2017::Day11
{
	using HexCoord = std::tuple<int, int, int>;

	HexCoord operator+(const HexCoord& lhs, const HexCoord& rhs)
	{
		return std::make_tuple(
			std::get<0>(lhs) + std::get<0>(rhs),
			std::get<1>(lhs) + std::get<1>(rhs),
			std::get<2>(lhs) + std::get<2>(rhs)
		);
	}

	HexEd::HexEd() : DayT(11, "Hex Ed") { }

	uint64_t HexEd::ExecutePart1(std::vector<HexDirection> directions)
	{
		// Map hex directions to directions in a cube coordinate system:
		std::map<HexDirection, HexCoord> dirVectors;

		// First coordinate: north/south
		dirVectors[HexDirection::North] = { 0, +1, -1 };
		dirVectors[HexDirection::South] = { 0, -1, +1 };

		// Second coordinate: northeast / southwest
		dirVectors[HexDirection::NorthEast] = { +1, 0, -1 };
		dirVectors[HexDirection::SouthWest] = { -1, 0, +1 };

		// Third coordinate: northwest / southeast
		dirVectors[HexDirection::NorthWest] = { -1, +1, 0 };
		dirVectors[HexDirection::SouthEast] = { +1, -1, 0 };

		// Sum up vectors for all movements:
		HexCoord pos { 0 , 0, 0 };
		for (auto hexDir : directions)
			pos = pos + dirVectors[hexDir];

		// Resulting distance:
		return 
			(std::abs(std::get<0>(pos)) + 
			std::abs(std::get<1>(pos)) +
			std::abs(std::get<2>(pos))) / 2;
	}

	uint64_t HexEd::ExecutePart2(std::vector<HexDirection> directions)
	{
		return uint64_t();
	}
}
