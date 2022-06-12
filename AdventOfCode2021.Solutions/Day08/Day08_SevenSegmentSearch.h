#pragma once
#include "DayT.h"
#include "SignalPatternProcessor.h"

namespace AdventOfCode::Year2021::Day08
{
	class SevenSegmentSearch : public DayT<SignalPatternProcessor>
	{
	public:
		SevenSegmentSearch();

	protected:
		uint64_t ExecutePart1(std::vector<SignalPatternObservation> patterns) override;
		uint64_t ExecutePart2(std::vector<SignalPatternObservation> patterns) override;
	};
}