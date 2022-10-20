#include "TicketProcessor.h"
#include "Utils.h"
#include <regex>

namespace AdventOfCode::Year2020::Day16
{
	std::pair<std::vector<Ticket>, TicketRules> TicketProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Ticket> tickets;
		std::vector<TicketField> fieldRules;

		bool ticketRules = true;

		// find ranges in rules:
		std::regex rangePattern = std::regex("([0-9]+)-([0-9]+)");
		std::smatch matches;

		if (!input.empty())
		{
			// Input is separated in three sections: fields / rules; one's own ticket; nearby tickets:
			for (const std::string& line : input)
			{
				// Parse rules at the beginning:
				if (ticketRules)
				{
					if (line.empty())
						ticketRules = false;
					else
					{
						std::vector<ValueInterval> ranges;

						// line can contain multiple range statements:
						std::string rule = line;
						do
						{
							// Number of matches == 3: the whole range plus the two capture groups
							if (std::regex_search(rule, matches, rangePattern) && matches.size() == 3)
							{
								int lower = atoi(matches[1].str().c_str());
								int upper = atoi(matches[2].str().c_str());

								ranges.push_back(ValueInterval(lower, upper));
							}
						} while ((rule = matches.suffix()).length() > 0);	// continue with rest of string
						
						fieldRules.push_back(TicketField(line.substr(0, line.find(':', 0)), ranges));
					}
				}
				// Parse ticket data afterwards:
				else
				{
					if (line.empty() || line.back() == ':')
						continue;	// skip labels "your ticket:" and "nearby tickets:" as well as empty lines
					else
					{
						tickets.push_back(Ticket(SplitLine<int>(line, ',', [](const std::string& val) { return atoi(val.c_str()); })));
					}
				}
			}
		}

		return std::make_pair(tickets, TicketRules(fieldRules));
	}
}


