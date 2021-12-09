#include "Day13_ShuttleSearch.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day13
{
	ShuttleSearch::ShuttleSearch() : DayTC(13, "Shuttle Search")
	{}

	uint64_t Day13::ShuttleSearch::ExecutePart1(std::vector<ShuttleLine> shuttleLines, int timestamp)
	{
		if (!shuttleLines.empty())
		{
			// For each line, get the next available departure time for the given timestamp:

			ShuttleLine& nextLine = *(std::min_element(shuttleLines.begin(), shuttleLines.end(),
				[timestamp](const ShuttleLine& a, const ShuttleLine& b) { return a.GetWaitTime(timestamp) < b.GetWaitTime(timestamp); }));

			return nextLine.GetWaitTime(timestamp) * nextLine.GetLineNo();
		}
		return 0;
	}
}