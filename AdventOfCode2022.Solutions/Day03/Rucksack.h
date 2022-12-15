#pragma once
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

namespace AdventOfCode::Year2022::Day03
{
	class Rucksack
	{
	public:
		using Item = char;

		Rucksack(auto itemsBegin, auto itemsEnd) :
			m_items(itemsBegin, itemsEnd)
		{ }

		// Find the only item that is contained in both compartments of one rucksack:
		Item GetDuplicateItem() const
		{
			// A given rucksack always has the same number of items in each of its two compartments, 
			// so the first half of the characters represent items in the first compartment, while the 
			// second half of the characters represent items in the second compartment.
			auto mid = m_items.begin() + m_items.size() / 2;

			// Find single item from the first half that's also in the second half:
			return *std::find_first_of(m_items.begin(), mid, mid + 1, m_items.end());
		}


		// Find badge in a group of this and two other rucksacks:
		Item GetBadge(const Rucksack& r1, const Rucksack& r2)
		{
			std::multiset<Item> items1(m_items.begin(), m_items.end());
			std::multiset<Item> items2(r1.m_items.begin(), r1.m_items.end());

			// First, intersect first two rucksacks:
			std::multiset<Item> r1_r2;
			std::set_intersection(
				items1.begin(), items1.end(),
				items2.begin(), items2.end(),
				std::inserter(r1_r2, r1_r2.begin())
			);

			// Second, find the first item from the third rucksack that's contained in th above set:
			return *std::find_first_of(r2.m_items.begin(), r2.m_items.end(), r1_r2.begin(), r1_r2.end());
		}

	private:
		std::vector<Item> m_items;
	};
}
