#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day15
{
	class RambunctiousRecitation : public DayT<IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>>
	{
	public:
		RambunctiousRecitation(int numberOfTurns);

	protected:
		uint64_t ExecutePart1(std::vector<int> input) override;

	private:
		int m_numberOfTurns;
	};
}


