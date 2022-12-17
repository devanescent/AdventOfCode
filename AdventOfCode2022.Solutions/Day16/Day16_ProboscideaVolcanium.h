#pragma once
#include "DayT.h"
#include "ValveProcessor.h"

namespace AdventOfCode::Year2022::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Proboscidea Volcanium
	// ---------------------------------------------------------------------------
	class ProboscideaVolcanium : public DayT<ValveProcessor>
	{
	public:
		ProboscideaVolcanium();

	protected:
		uint64_t ExecutePart1(std::map<std::string, Valve> valves) override;
		uint64_t ExecutePart2(std::map<std::string, Valve> valves) override;
	};
}
