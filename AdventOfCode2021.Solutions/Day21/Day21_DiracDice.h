#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day21
{
	class DiracDice : public Day<>
	{
	public:
		DiracDice();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}