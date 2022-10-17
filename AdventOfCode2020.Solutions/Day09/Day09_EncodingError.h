#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day09
{
	class EncodingError : public DayT<LargeIntProcessor>
	{
	public:
		EncodingError(size_t preambleLen = 25);

	protected:
		uint64_t ExecutePart1(std::vector<uint64_t> input) override;
		uint64_t ExecutePart2(std::vector<uint64_t> input) override;

	private:
		size_t m_preambleLen;
	};
}


