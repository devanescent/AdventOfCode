#include "Day16_TicketTranslation.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2020::Day16
{
	TicketTranslation::TicketTranslation() : DayTC(16, "Ticket Translation") {}

	uint64_t TicketTranslation::ExecutePart1(std::vector<Ticket> tickets, TicketRules rules)
	{
		// skip the first ticket which is one's own ticket
		return std::accumulate(tickets.begin() + 1, tickets.end(), 0ull,
			[&rules](uint64_t totalErrorRate, const Ticket& t) 
			{ 
				int errorRate;
				return !rules.Validate(t, errorRate) ? totalErrorRate + errorRate : totalErrorRate;
			}
		);
	}

	uint64_t TicketTranslation::ExecutePart2(std::vector<Ticket> tickets, TicketRules rules)
	{
		std::map<std::string, std::set<int>> totalMatches;

		// skip the first ticket which is one's own ticket
		for (auto ticketIt = tickets.begin() + 1; ticketIt != tickets.end(); ++ticketIt)
		{
			int errorRate;
			if (rules.Validate(*ticketIt, errorRate))
			{
				// Get matches and intersect with existing matches:
				auto matches = rules.MatchValuesToFields(*ticketIt);

				if (totalMatches.empty())
					totalMatches = matches; // Initialize with first valid set
				else
				{
					for (auto& match : matches)
					{
						// The new set has to have at least some elements missing for the intersection to have any effect:
						if (match.second.size() < 20)
						{
							std::set<int> result;
							std::set_intersection(
								totalMatches[match.first].begin(), totalMatches[match.first].end(),
								match.second.begin(), match.second.end(),
								std::inserter(result, result.end())
							);
							totalMatches[match.first] = result;
						}
					}
				}
			}
		}
		
		// Result is product of departure values:
		uint64_t departureValue = 1;

		// Now, deduce matching values for fields:
		do
		{
			// Find a field that has just one possible value index matching:
			auto field = std::find_if(totalMatches.begin(), totalMatches.end(), 
				[](const auto& match) { return match.second.size() == 1; }
			);

			// The single remaining value:
			int valueIndex = *(field->second.begin());

			// If this field starts with departure, update departure value:
			if (field->first.rfind("departure", 0) == 0)
				departureValue *= tickets[0].Values()[valueIndex];

			// Remove the matching index from all other fields:
			for (auto it = totalMatches.begin(); it != totalMatches.end(); ++it)
			{
				if (it != field) it->second.erase(valueIndex);
			}

			// Remove the entry itself:
			totalMatches.erase(field);

		} while (totalMatches.size() > 0);

		return departureValue;
	}
}