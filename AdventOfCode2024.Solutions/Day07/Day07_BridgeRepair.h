#pragma once
#include "DayT.h"
#include "BridgeCalibrationsProcessor.h"

namespace AdventOfCode::Year2024::Day07
{
	// ---------------------------------------------------------------------------
	// Day07: Bridge Repair
	// ---------------------------------------------------------------------------
	class BridgeRepair : public DayT<BridgeCalibrationsProcessor>
	{
	public:
		BridgeRepair();

	protected:
		uint64_t ExecutePart1(std::vector<Calibration> calibrations) override;
		uint64_t ExecutePart2(std::vector<Calibration> calibrations) override;
	};
}
