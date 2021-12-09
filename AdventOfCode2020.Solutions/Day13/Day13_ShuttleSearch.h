#pragma once
#include "DayTC.h"
#include "ShuttleLine.h"
#include "ShuttleLineProcessor.h"

namespace AdventOfCode::Year2020::Day13 
{
	class ShuttleSearch : public DayTC<ShuttleLine, int, ShuttleLineProcessor>
	{
	public:
		ShuttleSearch();

	protected:
		uint64_t ExecutePart1(std::vector<ShuttleLine> shuttleLines, int timestamp) override;
	};
}

