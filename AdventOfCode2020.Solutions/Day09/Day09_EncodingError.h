#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day09
{
	class EncodingError : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		EncodingError(int preambleLen);

	protected:
		uint64_t ExecutePart1(std::vector<int> input) override;

	private:
		int m_preambleLen;
	};
}


