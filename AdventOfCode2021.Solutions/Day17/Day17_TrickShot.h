#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day17
{
	class TrickShot : public Day
	{
	public:
		TrickShot();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
	};
}