#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day21
{
	class DiracDice : public Day
	{
	public:
		DiracDice();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
	};
}