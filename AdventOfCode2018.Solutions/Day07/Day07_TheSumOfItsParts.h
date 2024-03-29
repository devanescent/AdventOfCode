#pragma once
#include "DayT.h"
#include "AssemblyStepsProcessor.h"

namespace AdventOfCode::Year2018::Day07
{
	// ---------------------------------------------------------------------------
	// Day 07: The Sum Of Its Parts 
	// ---------------------------------------------------------------------------
	class TheSumOfItsParts : public DayT<AssemblyStepsProcessor, std::string, uint64_t>
	{
	public:
		TheSumOfItsParts(int numWorkers, int workTimeOffset);

		std::string ExecutePart1(std::vector<AssemblyStep> steps) override;
		uint64_t ExecutePart2(std::vector<AssemblyStep> steps) override;

	private:
		int m_numWorkers;
		int m_workTimeOffset;
	};
}