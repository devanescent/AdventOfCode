#pragma once
#include <string>
#include <set>

namespace AdventOfCode::Year2020::Day07
{
	class Bag
	{
	public:
		Bag(std::string name) : m_name(std::move(name)) {}

		const std::string& GetName() const { return m_name; }

		void AddBagToContent(std::string name, int count)
		{
			m_containedBags.emplace_back(name, count);
		}

		std::vector<std::pair<std::string, int>>::const_iterator begin() const { return m_containedBags.begin(); }
		std::vector<std::pair<std::string, int>>::const_iterator end() const { return m_containedBags.end(); }

	private:
		std::string m_name;
		std::vector<std::pair<std::string, int>> m_containedBags; // Name + Count
	};
}