#include "Day16_TicketTranslation.h"
#include <numeric>

namespace AdventOfCode::Year2020::Day16
{
	TicketTranslation::TicketTranslation() : DayTC(16, "Ticket Translation") {}

	uint64_t TicketTranslation::ExecutePart1(std::vector<Ticket> tickets, TicketRules rules)
	{
		if (tickets.size() > 1)
		{
			// skip the first ticket which is one's own ticket
			return std::accumulate(tickets.begin() + 1, tickets.end(), 0ull,
				[&rules](uint64_t totalErrorRate, const Ticket& t) { return totalErrorRate + rules.Validate(t); }
			);
		}
		return 0;
	}
}