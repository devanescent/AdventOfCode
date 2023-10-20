#include "Day11_HexEd.h"
#include <numeric>

namespace AdventOfCode::Year2017::Day11
{
	HexCoord operator+(const HexCoord& lhs, const HexCoord& rhs)
	{
		return std::make_tuple(
			std::get<0>(lhs) + std::get<0>(rhs),
			std::get<1>(lhs) + std::get<1>(rhs),
			std::get<2>(lhs) + std::get<2>(rhs)
		);
	}

	uint64_t GetDistance(const HexCoord& c)
	{
		return (
			std::abs(std::get<0>(c)) + 
			std::abs(std::get<1>(c)) +
			std::abs(std::get<2>(c))
		) / 2;
	}

	HexEd::HexEd() : DayT(11, "Hex Ed")
	{ 
		// Map hex directions to directions in a cube coordinate system:
		m_dirVectors[HexDirection::North] = { 0, +1, -1 };
		m_dirVectors[HexDirection::South] = { 0, -1, +1 };
		m_dirVectors[HexDirection::NorthEast] = { +1, 0, -1 };
		m_dirVectors[HexDirection::SouthWest] = { -1, 0, +1 };
		m_dirVectors[HexDirection::NorthWest] = { -1, +1, 0 };
		m_dirVectors[HexDirection::SouthEast] = { +1, -1, 0 };
	}

	uint64_t HexEd::ExecutePart1(std::vector<HexDirection> directions)
	{
		HexCoord pos { 0 , 0, 0 };

		// Sum up vectors for all movements:
		for (auto hexDir : directions)
			pos = pos + m_dirVectors[hexDir];

		// Resulting distance:
		return GetDistance(pos);
	}

	uint64_t HexEd::ExecutePart2(std::vector<HexDirection> directions)
	{
		HexCoord pos{ 0 , 0, 0 };
		uint64_t maxDistance = 0ull;

		// Sum up vectors for all movements while keeping track of maximum distance:
		for (auto hexDir : directions)
		{
			pos = pos + m_dirVectors[hexDir];
			maxDistance = std::max(maxDistance, GetDistance(pos));
		}

		return maxDistance;
	}
}
