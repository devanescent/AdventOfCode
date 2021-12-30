#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day25
{
	class SeaCucumber : public Day
	{
	public:
		SeaCucumber();

		uint64_t GetResultOnPart1(std::vector<std::string> cucumbers) override;
	};
}