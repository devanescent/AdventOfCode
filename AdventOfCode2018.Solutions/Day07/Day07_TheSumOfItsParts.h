#pragma once
#include "DayT.h"
#include "InstructionProcessor.h"

namespace AdventOfCode::Year2018::Day07
{
	// ---------------------------------------------------------------------------
	// Day 07: The Sum Of Its Parts 
	// ---------------------------------------------------------------------------
	class TheSumOfItsParts : public DayT<InstructionProcessor>
	{
	public:
		TheSumOfItsParts(int numWorkers, int workTimeOffset);

		uint64_t ExecutePart1(std::vector<InstructionStep> steps) override;
		uint64_t ExecutePart2(std::vector<InstructionStep> steps) override;

	private:
		int m_numWorkers;
		int m_workTimeOffset;
	};
}