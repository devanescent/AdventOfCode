#pragma once
#include <algorithm>
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

			// Find single item in both compartments:
			std::multiset<Item> firstCompartment(m_items.begin(), mid);
			std::multiset<Item> secondCompartment(mid, m_items.end());

			// Find duplicate item:
			std::vector<Item> duplicateItem;

			std::set_intersection(
				firstCompartment.begin(), firstCompartment.end(),
				secondCompartment.begin(), secondCompartment.end(),
				std::back_inserter(duplicateItem)
			);

			return duplicateItem[0]; // should only be one single item
		}


		// Find badge in a group of this and two other rucksacks:
		Item GetBadge(const Rucksack& r1, const Rucksack& r2)
		{
			std::multiset<Item> items1(m_items.begin(), m_items.end());
			std::multiset<Item> items2(r1.m_items.begin(), r1.m_items.end());
			std::multiset<Item> items3(r2.m_items.begin(), r2.m_items.end());

			// First, intersect first two rucksacks:
			std::multiset<Item> r1_r2;
			std::set_intersection(
				items1.begin(), items1.end(),
				items2.begin(), items2.end(),
				std::inserter(r1_r2, r1_r2.begin())
			);

			// Second, intersect with the third rucksack to find the badge:
			std::vector<Item> badges;
			std::set_intersection(
				r1_r2.begin(), r1_r2.end(),
				items3.begin(), items3.end(),
				std::back_inserter(badges)
			);

			return badges[0];
		}

	private:
		std::vector<Item> m_items;
	};
}
