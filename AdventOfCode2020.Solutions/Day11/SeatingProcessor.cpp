#include "SeatingProcessor.h"

namespace AdventOfCode::Year2020::Day11
{
	std::vector<SeatRow> SeatingProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SeatRow> seatRows;

		for (const std::string& inputLine : input)
		{
			SeatRow row;

			for (const char& c : inputLine)
			{
				if (c == OCCUPIED_SEAT)
					row.push_back(Seat(Seat::SeatType::OCCUPIED));
				else if (c == EMPTY_SEAT)
					row.push_back(Seat(Seat::SeatType::EMPTY));
				else
					row.push_back(Seat(Seat::SeatType::NO_SEAT));
			}

			seatRows.push_back(row);
		}

		return seatRows;
	}
}
