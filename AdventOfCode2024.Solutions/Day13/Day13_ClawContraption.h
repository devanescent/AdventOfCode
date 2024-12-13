#pragma once
#include "DayT.h"
#include "ClawMachineProcessor.h"

namespace AdventOfCode::Year2024::Day13
{
	// ---------------------------------------------------------------------------
	// Day13: Claw Contraption
	// ---------------------------------------------------------------------------
	class ClawContraption : public DayT<ClawMachineProcessor>
	{
	public:
		ClawContraption();

	protected:
		uint64_t ExecutePart1(std::vector<ClawMachine> clawMachines) override;
		uint64_t ExecutePart2(std::vector<ClawMachine> clawMachines) override;
	};
}
