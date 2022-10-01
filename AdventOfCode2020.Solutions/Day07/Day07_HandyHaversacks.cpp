#include "Day07_HandyHaversacks.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day07
{
	HandyHaversacks::HandyHaversacks() : DayT(7, "Handy Haversacks") {}

	uint64_t Day07::HandyHaversacks::ExecutePart1(std::map<std::string, Bag> bags)
	{
		m_bags = bags;

		// Keep track of which bags can contain a "shiny gold" bag during processing
		std::map<std::string, bool> canContainShinyGold;

		int count = 0;
		for (const auto& bagEntry : m_bags)
		{
			// Bag cannot contain itself:
			if (bagEntry.first == "shiny gold")
				continue;

			// Search bag contents for shiny gold bags:
			count += CheckBagContents(bagEntry.second, canContainShinyGold);
		}

		return count;
	}

	uint64_t Day07::HandyHaversacks::ExecutePart2(std::map<std::string, Bag> bags)
	{
		m_bags = bags;

		// Keep track of which bags contain how many other bags during processing:
		std::map<std::string, uint64_t> bagCounts;

		return CountBagContents(m_bags.at("shiny gold"), bagCounts);
	}

	bool HandyHaversacks::CheckBagContents(const Bag& bag, std::map<std::string, bool>& canContainShinyGold)
	{
		auto info = canContainShinyGold.find(bag.GetName());
		if (info != canContainShinyGold.end())
		{
			// Contents of this bag have already been evaluated:
			return info->second;
		}
		else
		{
			// Otherwise, find out if this bag (or one of its contents) can contain the shiny gold bag:
			for (const auto& bagContents : bag)
			{
				if (bagContents.first == "shiny gold")
				{
					// Current bag contains a shiny gold bag: take note and return true
					canContainShinyGold[bag.GetName()] = true;
					return true;
				}
				// Otherwise, search the contents recursively:
				else if (CheckBagContents(m_bags.at(bagContents.first), canContainShinyGold))
					return true;
			}

			return false;
		}
	}

	uint64_t HandyHaversacks::CountBagContents(const Bag& bag, std::map<std::string, uint64_t>& bagCounts)
	{
		auto info = bagCounts.find(bag.GetName());
		if (info != bagCounts.end())
		{
			// Contents of this bag have already been counted:
			return info->second;
		}
		else
		{
			// Otherwise, count conatained bags:
			uint64_t totalCount = 0;
			for (const auto& bagContents : bag)
			{
				auto count = CountBagContents(m_bags.at(bagContents.first), bagCounts);
				bagCounts[bagContents.first] = count;

				totalCount += (count + 1) * bagContents.second; // +1 for the bag itself in addition to its contents
			}

			return totalCount;
		}
	}
}
