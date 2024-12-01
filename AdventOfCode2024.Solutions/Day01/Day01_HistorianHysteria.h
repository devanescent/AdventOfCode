#pragma once
#include "DayT.h"
#include "LocationsListProcessor.h"

namespace AdventOfCode::Year2024::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: Historian Hysteria
	// ---------------------------------------------------------------------------
	class HistorianHysteria : public DayT<LocationsListProcessor>
	{
	public:
		HistorianHysteria();

	protected:
		uint64_t ExecutePart1(std::vector<LocationList> locationLists) override;
		uint64_t ExecutePart2(std::vector<LocationList> locationLists) override;
	};
}
