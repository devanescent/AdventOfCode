#pragma once
#include "DayT.h"
#include "HexGridProcessor.h"
#include <map>

namespace AdventOfCode::Year2017::Day11
{
	using HexCoord = std::tuple<int, int, int>;

	// ---------------------------------------------------------------------------
	// Day11: Hex Ed
	// ---------------------------------------------------------------------------
	class HexEd : public DayT<HexGridProcessor>
	{
	public:
		HexEd();

	protected:
		uint64_t ExecutePart1(std::vector<HexDirection> directions) override;
		uint64_t ExecutePart2(std::vector<HexDirection> directions) override;

	private:
		std::map<HexDirection, HexCoord> m_dirVectors;
	};
}
