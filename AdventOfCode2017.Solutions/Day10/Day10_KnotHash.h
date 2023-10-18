#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2017::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: Knot Hash
	// ---------------------------------------------------------------------------
	class KnotHash : public DayT<IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>>
	{
	public:
		KnotHash();

		uint64_t ExecutePart1(std::vector<int> lengths) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;

		void SetNumberListLength(size_t listLength) { m_numberListLength = listLength; }

	private:
		size_t m_numberListLength = 256;

		void RunKnotHashRound(std::vector<int>& numbers, const std::vector<int>& lengths, int& listStartIndex, int& skipSize);
	};
}
