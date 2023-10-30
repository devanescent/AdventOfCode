#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day25
{
	class SeaCucumber : public Day<>
	{
	public:
		SeaCucumber();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> cucumbers) override;
	};
}