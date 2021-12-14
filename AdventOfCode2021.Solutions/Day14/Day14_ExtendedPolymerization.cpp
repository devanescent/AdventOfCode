#include "Day14_ExtendedPolymerization.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2021::Day14
{
	ExtendedPolymerization::ExtendedPolymerization() : DayTC(14, "Extended Polymerization") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t ExtendedPolymerization::ExecutePart1(std::vector<PolymerRule> rules, std::string polymerTemplate)
	{
		return ApplyPolymerization(polymerTemplate, rules, 10);
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t ExtendedPolymerization::ExecutePart2(std::vector<PolymerRule> rules, std::string polymerTemplate)
	{
		return ApplyPolymerization(polymerTemplate, rules, 40);
	}

	// ---------------------------------------------------------------------------
	// ApplyPolymerization
	// Applies the polymerization rules to the template, a number of <count> times
	// ---------------------------------------------------------------------------
	uint64_t ExtendedPolymerization::ApplyPolymerization(const std::string& polymerTemplate, std::vector<PolymerRule>& rules, int count)
	{
		// Keep count of pairs inside the polymer
		std::map<std::pair<char, char>, uint64_t> pairCounts;

		// Add all pairs of the template to the counts:
		for (int i = 0; i < polymerTemplate.length() - 1; ++i)
			++pairCounts[std::make_pair(polymerTemplate[i], polymerTemplate[i + 1])];

		// Apply polymerization rules
		for (int step = 0; step < count; ++step)
		{
			// Recalculate the polymere pair counts after each step
			std::map<std::pair<char, char>, uint64_t> nextStepPairCounts;
			for (const auto& rule : rules)
			{
				auto it = pairCounts.find(rule.PolyPair);
				if (it != pairCounts.end())
				{
					nextStepPairCounts[std::make_pair(rule.PolyPair.first, rule.InsertedElement)] += it->second;
					nextStepPairCounts[std::make_pair(rule.InsertedElement, rule.PolyPair.second)] += it->second;
				}
			}
			pairCounts = nextStepPairCounts;
		}

		// Sum up counts for all polymer in all pairs
		// Because each polymer (except the very first and very last) is contained in two pairs,
		// the resulting count will be double the actual amount
		std::map<char, uint64_t> polymerCounts;
		for (const auto& pairCount : pairCounts)
		{
			polymerCounts[pairCount.first.first] += pairCount.second;
			polymerCounts[pairCount.first.second] += pairCount.second;
		}

		// To complete, add one count for the first and last polymer of the template:
		++polymerCounts[polymerTemplate.front()];
		++polymerCounts[polymerTemplate.back()];

		// Determine minimum and maximum element and take their difference:
		auto itPair = std::minmax_element(polymerCounts.begin(), polymerCounts.end(),
			[](const std::pair<char, uint64_t>& a, const std::pair<char, uint64_t>& b)
			{
				return a.second < b.second;
			}
		);

		// Divide by 2 to make up for the doubled count from above:
		return (itPair.second->second - itPair.first->second) / 2; 
	}
}
