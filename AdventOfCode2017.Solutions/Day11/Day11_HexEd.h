#pragma once
#include "DayT.h"
#include "HexGridProcessor.h"

namespace AdventOfCode::Year2017::Day11
{
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
	};
}
