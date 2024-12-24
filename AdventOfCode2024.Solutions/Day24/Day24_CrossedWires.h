#pragma once
#include "DayTC.h"
#include "LogicGateProcessor.h"

namespace AdventOfCode::Year2024::Day24
{
	// ---------------------------------------------------------------------------
	// Day24: Crossed Wires
	// ---------------------------------------------------------------------------
	class CrossedWires : public DayTC<LogicGateProcessor, uint64_t, std::string>
	{
	public:
		CrossedWires();

	protected:
		uint64_t ExecutePart1(std::vector<LogicGate> logicGates, WireInputs inputs) override;
		std::string ExecutePart2(std::vector<LogicGate> logicGates, WireInputs inputs) override;
	};
}
