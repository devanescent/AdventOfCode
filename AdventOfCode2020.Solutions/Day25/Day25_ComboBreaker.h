#pragma once
#include "DayT.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day25
{
	class ComboBreaker : public DayT<IntProcessor<IntProcessingMode::ValuePerLine>>
	{
	public:
		ComboBreaker();

	protected:
		uint64_t ExecutePart1(std::vector<int> publicKeys) override;

	private:
		uint64_t Encrypt(uint64_t subject, int loops, uint64_t startValue = 1);
	};
}


