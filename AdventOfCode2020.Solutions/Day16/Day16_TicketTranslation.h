#pragma once
#include "DayTC.h"
#include "Ticket.h"
#include "TicketProcessor.h"

namespace AdventOfCode::Year2020::Day16
{
	class TicketTranslation : public DayTC<TicketProcessor>
	{
	public:
		TicketTranslation();

	protected:
		uint64_t ExecutePart1(std::vector<Ticket> tickets, TicketRules rules) override;
	};
}

