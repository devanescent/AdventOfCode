#pragma once
#include <string>
#include <set>

namespace AdventOfCode::Year2020::Day07
{
	class Bag
	{
	public:
		Bag(std::string name) : 
			m_name(name), m_isMarked(false)
		{}

		const std::string& GetName() { return m_name; }

		void AddContainer(Bag* container)
		{
			m_containers.insert(container);
		}

		int CountUniqueContainers()
		{
			int count = 0;
			for (Bag* b : m_containers)
			{
				if (!b->m_isMarked)
				{
					b->m_isMarked = true;
					count += (1 + b->CountUniqueContainers());
				}
			}

			return count;
		}

	private:
		std::string m_name;
		bool m_isMarked;
		std::set<Bag*> m_containers;
	};
}