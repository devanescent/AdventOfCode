#pragma once
#include "DayT.h"
#include "InitSequenceProcessor.h"

namespace AdventOfCode::Year2023::Day15
{
	// ---------------------------------------------------------------------------
	// Day15: Lens Library
	// ---------------------------------------------------------------------------
	class LensLibrary : public DayT<InitSequenceProcessor>
	{
	public:
		LensLibrary();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> initSteps) override;
		uint64_t ExecutePart2(std::vector<std::string> initSteps) override;
	};
}
