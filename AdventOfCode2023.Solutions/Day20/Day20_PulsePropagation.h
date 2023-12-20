#pragma once
#include "DayT.h"
#include "PulseModuleProcessor.h"

namespace AdventOfCode::Year2023::Day20
{
	// ---------------------------------------------------------------------------
	// Day20: Pulse Propagation
	// ---------------------------------------------------------------------------
	class PulsePropagation : public DayT<PulseModuleProcessor>
	{
	public:
		PulsePropagation();

	protected:
		uint64_t ExecutePart1(std::vector<PulseModule> modules) override;
		uint64_t ExecutePart2(std::vector<PulseModule> modules) override;
	};
}
