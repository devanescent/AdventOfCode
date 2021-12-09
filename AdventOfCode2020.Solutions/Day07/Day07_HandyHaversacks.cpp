#include "Day07_HandyHaversacks.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day07
{
	HandyHaversacks::HandyHaversacks(std::string bagName) : DayT(7, "Handy Haversacks"), 
		m_bagName(bagName)
	{}

	uint64_t Day07::HandyHaversacks::ExecutePart1(std::vector<Bag*> bags)
	{
		if (!bags.empty())
		{
			Bag* b = *(std::find_if(bags.begin(), bags.end(), [&](Bag* b) { return b->GetName() == m_bagName; }));
			return b->CountUniqueContainers();
		}
		return 0;
	}
}
