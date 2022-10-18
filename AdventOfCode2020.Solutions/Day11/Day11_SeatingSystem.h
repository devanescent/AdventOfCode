#pragma once
#include "DayT.h"
#include "Seat.h"
#include "SeatingProcessor.h"

namespace AdventOfCode::Year2020::Day11
{
	class SeatingSystem : public DayT<SeatingProcessor>
	{
	public:
		SeatingSystem();

	protected:
		uint64_t ExecutePart1(std::vector<SeatRow> seats) override;
		uint64_t ExecutePart2(std::vector<SeatRow> seats) override;

	private:
		uint64_t ApplySeatingRules(std::vector<SeatRow>& seats, bool checkAllVisibleSeats, int occupationTolerance);
		bool UpdateSeats(std::vector<SeatRow>& seats, uint64_t& occCount);
		int CountOccupiedNeighbors(std::vector<SeatRow>& seats, int seatRow, int seatCol, bool checkAllVisibleSeats);
	};
}