#include "PrintingRulesProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day05
{
	std::pair<std::vector<PageUpdate>, PageOrderingRules> PrintingRulesProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<PageUpdate>, PageOrderingRules> printRules;

		auto& updates = printRules.first;
		auto& orderingRules = printRules.second;

		bool isFirstSection = true;

		for (const auto& line : input)
		{
			if (line.empty())
			{
				isFirstSection = false;
				continue;
			}

			std::istringstream iss(line);

			if (isFirstSection)
			{
				// First section: ordering rules
				char separator;
				int page1, page2;
				iss >> page1 >> separator >> page2;
				orderingRules.emplace_back(std::make_pair(page1, page2));
			}
			else
			{
				// Second section: updates
				char separator;
				int page;

				PageUpdate update;
				while (iss >> page)
				{
					update.push_back(page);
					iss >> separator;
				}

				updates.emplace_back(update);
			}
		}

		return printRules;
	}
}
