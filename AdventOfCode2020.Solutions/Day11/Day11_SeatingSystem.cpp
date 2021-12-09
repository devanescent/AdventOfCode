#include "Day11_SeatingSystem.h"

namespace AdventOfCode::Year2020::Day11
{
	SeatingSystem::SeatingSystem() : DayT(11, "Seating System") {}

	// Applies the seating rules to all seats until no seats change:
	// - If a seat is empty and there are no occupied seats adjacent to it, the 
	//   seat becomes occupied.
	// - If a seat is occupied and four or more seats adjacent to it are also 
	//   occupied, the seat becomes empty.
	// - Otherwise, the seat's state does not change.
	uint64_t SeatingSystem::ExecutePart1(std::vector<SeatRow> seats)
	{
		int occCount = 0;
		do
		{
			for (int r = 0; r < (int)seats.size(); ++r)
			{
				for (int c = 0; c < (int)seats[r].size(); ++c)
				{
					if (seats[r][c].IsSeat())
					{
						int neighborCnt = CountOccupiedNeighbors(seats, r, c);
						bool isOcc = seats[r][c].IsOccupied();

						if (isOcc && neighborCnt >= 4)
							seats[r][c].SetNextState(Seat::SeatType::EMPTY);
						else if (!isOcc && neighborCnt == 0)
							seats[r][c].SetNextState(Seat::SeatType::OCCUPIED);
					}
				}
			}

		} while (UpdateSeats(seats, occCount));

		return occCount;
	}

	// ---------------------------------------------------------------------------
	bool SeatingSystem::UpdateSeats(std::vector<SeatRow>& seats, int& occCount)
	{
		// Updates all seats for next iteration, 
		// returns true if at least one seat has been updated
		bool rc = false;

		for (int r = 0; r < (int)seats.size(); ++r)
		{
			for (int c = 0; c < (int)seats[r].size(); ++c)
			{
				if (seats[r][c].IsSeat() && seats[r][c].Update())
				{
					rc = true;
					if (seats[r][c].IsOccupied())
						occCount++;
					else
						occCount--;
				}
			}
		}

		return rc;
	}

	// ---------------------------------------------------------------------------
	int Day11::SeatingSystem::CountOccupiedNeighbors(std::vector<SeatRow>& seats, int seatRow, int seatCol)
	{
		int count = 0;

		// all neighbors: 
		for (int r = seatRow - 1; r <= seatRow + 1; ++r)
		{
			for (int c = seatCol - 1; c <= seatCol + 1; ++c)
			{
				// Valid seat?
				if (r >= 0 && r < (int)seats.size() &&		// valid row
					 c >= 0 && c < (int)seats[r].size() &&	// valid column
					!(c == seatCol && r == seatRow))		// not center seat (= self)
				{
					if (seats[r][c].IsOccupied())
						count++;
				}
				
			}
		}
		return count;
	}
}
