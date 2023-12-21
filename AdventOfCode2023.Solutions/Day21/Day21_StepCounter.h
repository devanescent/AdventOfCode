#pragma once
#include "Day.h"

namespace AdventOfCode::Year2023::Day21
{
	// ---------------------------------------------------------------------------
	// Day21: Step Counter
	// ---------------------------------------------------------------------------
	class StepCounter : public Day<>
	{
	public:
		StepCounter();
		void SetStepCountPart1(uint64_t stepCount) { m_stepCountPart1 = stepCount; }

	protected:
		uint64_t ExecutePart1(std::vector<std::string> gardenMap) override;
		uint64_t ExecutePart2(std::vector<std::string> gardenMap) override;

	private:
		// Overwrite for tests:
		uint64_t m_stepCountPart1;
	};
}
