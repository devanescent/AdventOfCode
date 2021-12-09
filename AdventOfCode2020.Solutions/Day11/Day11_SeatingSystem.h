#pragma once
#include "DayT.h"
#include "Seat.h"
#include "SeatingProcessor.h"

namespace AdventOfCode::Year2020::Day11
{
	class SeatingSystem : public DayT<SeatRow, SeatingProcessor>
	{
	public:
		SeatingSystem();

	protected:
		uint64_t ExecutePart1(std::vector<SeatRow> seats) override;

	private:
		bool UpdateSeats(std::vector<SeatRow>& seats, int& occCount);
		int CountOccupiedNeighbors(std::vector<SeatRow>& seats, int seatRow, int seatCol);
	};
}