#pragma once
#include "DayT.h"
#include "RoomProcessor.h"

namespace AdventOfCode::Year2018::Day20
{
	// ---------------------------------------------------------------------------
	// Day20: A Regular Map
	// ---------------------------------------------------------------------------
	class ARegularMap : public DayT<RoomProcessor>
	{
	public:
		ARegularMap();

	protected:
		uint64_t ExecutePart1(std::vector<Room> rooms) override;
		uint64_t ExecutePart2(std::vector<Room> rooms) override;
	};
}
