#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day17
{
	class TrickShot : public Day<>
	{
	public:
		TrickShot();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
	};
}