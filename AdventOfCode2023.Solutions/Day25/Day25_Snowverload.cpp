#include "Day25_Snowverload.h"
#include <map>
#include <random>

namespace AdventOfCode::Year2023::Day25
{
	Snowverload::Snowverload() : DayT(25, "Snowverload") { }

	uint64_t Snowverload::ExecutePart1(std::vector<Wiring> origConnections)
	{
		// Merge connections via Karger's algorithm to find minimal cut set:
		// -> Because the alorithm works randomly, retry until the cut set has exactly size 3
		std::random_device rd;
		std::mt19937 gen(rd());

		std::vector<Wiring> connections;
		std::map<std::string, int> mergedComponents;

		do
		{
			// Initialize data from original data set each try
			connections = origConnections;
			mergedComponents.clear();
			for (const auto& con : connections)
			{
				mergedComponents.emplace(std::make_pair(con.Comp1, 1));
				mergedComponents.emplace(std::make_pair(con.Comp2, 1));
			}

			// Remove connections until only two nodes remain:
			while (mergedComponents.size() > 2)
			{
				// Pick random connection:
				auto rndIt = connections.begin();
				std::uniform_int_distribution<> distr(0, connections.size() - 1);
				std::advance(rndIt, distr(gen));

				// Remove wire together with the second component and attach all its connections to the first component:
				Wiring wireToRemove = *rndIt;
				std::erase_if(connections, [&wireToRemove](const auto& con) { return con == wireToRemove; });

				std::vector<Wiring> rewired;
				auto conIt = connections.begin();
				while (conIt != connections.end())
				{
					if (conIt->Comp1 == wireToRemove.Comp2)
					{
						rewired.emplace_back(wireToRemove.Comp1, conIt->Comp2);
						conIt = connections.erase(conIt);
					}
					else if (conIt->Comp2 == wireToRemove.Comp2)
					{
						rewired.emplace_back(wireToRemove.Comp1, conIt->Comp1);
						conIt = connections.erase(conIt);
					}
					else
						++conIt;
				}

				// Add rewired connections, update merged nodes:
				connections.insert(connections.end(), rewired.begin(), rewired.end());

				mergedComponents[wireToRemove.Comp1] += mergedComponents[wireToRemove.Comp2];
				mergedComponents.erase(wireToRemove.Comp2);
			}

		} while (connections.size() != 3);
	
		// Only two components will remain: the number of nodes merged into them is the size of each subset
		return mergedComponents.begin()->second * (++mergedComponents.begin())->second;
	}
}
