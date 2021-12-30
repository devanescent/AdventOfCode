#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day21
{
	class DiracDice : public Day
	{
	public:
		DiracDice();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}