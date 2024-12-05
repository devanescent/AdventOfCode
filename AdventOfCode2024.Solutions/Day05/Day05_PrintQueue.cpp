#include "Day05_PrintQueue.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2024::Day05
{
	PrintQueue::PrintQueue() : DayTC(5, "Print Queue") { }

	bool IsUpdateValid(const PageUpdate& update, const PageOrderingRules& orderRules)
	{
		// Check if each pair of page numbers in the update is valid according to the ordering rules:
		for (int i = 0; i < update.size() - 1; ++i)
		{
			for (int j = i + 1; j < update.size(); ++j)
			{
				// Search if any rule requires reverse ordering of this pair:
				auto backwards = std::make_pair(update[j], update[i]);
				if (std::find(orderRules.begin(), orderRules.end(), backwards) != orderRules.end())
				{
					// If such a rule was found, the update is not valid:
					return false;
				}
			}
		}

		// If no rule was violated the update is valid:
		return true;
	}


	uint64_t PrintQueue::ExecutePart1(std::vector<PageUpdate> updates, PageOrderingRules orderRules)
	{
		return std::accumulate(updates.begin(), updates.end(), 0ull,
			[&orderRules](uint64_t middlePageNumSum, const PageUpdate& update)
			{
				// Sum up only numbers from valid updates:
				if (IsUpdateValid(update, orderRules))
				{
					size_t mid = update.size() / 2;
					return middlePageNumSum + update[mid];
				}
				else
					return middlePageNumSum;
			});
	}

	uint64_t PrintQueue::ExecutePart2(std::vector<PageUpdate> updates, PageOrderingRules orderRules)
	{
		// Sort function according to the ordering rules:
		auto fSort = [&orderRules](int p1, int p2)
			{
				// p1 < p2 if a rule exists:
				auto orderRule = std::find(orderRules.begin(), orderRules.end(), std::make_pair(p1, p2));
				return orderRule != orderRules.end();
			};

		uint64_t middlePageNumSum = 0;

		for (auto& update : updates)
		{
			// Sum up only numbers from invalid updates:
			if (!IsUpdateValid(update, orderRules))
			{
				size_t mid = update.size() / 2;

				// Sort for middle element:
				std::nth_element(update.begin(), update.begin() + mid, update.end(), fSort);
				middlePageNumSum += update[mid];
			}
		}

		return middlePageNumSum;
	}
}
