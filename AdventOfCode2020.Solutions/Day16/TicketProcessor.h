#pragma once
#include "InputProcessorWithContext.h"
#include "Ticket.h"

namespace AdventOfCode::Year2020::Day16
{
	class TicketProcessor : public InputProcessorWithContextBase<Ticket, TicketRules>
	{
	public:
		std::pair<std::vector<Ticket>, TicketRules> Process(std::vector<std::string> input) override;
	};

}

