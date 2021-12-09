#pragma once
#include "InputProcessor.h"
#include "Seat.h"

namespace AdventOfCode::Year2020::Day11
{
	class SeatingProcessor : public InputProcessorBase<SeatRow>
	{
	public:
		std::vector<SeatRow> Process(std::vector<std::string> input) override;

	private:
		const char NO_SEAT = '.';
		const char EMPTY_SEAT = 'L';
		const char OCCUPIED_SEAT = '#';
	};
}
