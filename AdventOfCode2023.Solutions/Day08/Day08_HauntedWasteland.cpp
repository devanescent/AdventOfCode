#include "Day08_HauntedWasteland.h"
#include <algorithm>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2023::Day08
{
	HauntedWasteland::HauntedWasteland() : DayTC(8, "Haunted Wasteland") { }

	uint64_t HauntedWasteland::ExecutePart1(std::vector<NetworkNode> nodes, std::vector<Direction> directions)
	{
		// Organize nodes by name:
		std::map<std::string, NetworkNode> map;
		for (const auto& node : nodes)
			map[node.Name] = node;

		// Start at AAA
		std::string currentNode = "AAA";

		auto dirIt = directions.begin();
		uint64_t steps = 0;
		while (currentNode != "ZZZ")
		{
			currentNode = map[currentNode].GetNextNode(*dirIt);
			++dirIt;
			++steps;

			if (dirIt == directions.end())
				dirIt = directions.begin();
		}

		return steps;
	}

	uint64_t HauntedWasteland::ExecutePart2(std::vector<NetworkNode> nodes, std::vector<Direction> directions)
	{
		// Organize nodes by name:
		std::map<std::string, NetworkNode> map;
		for (const auto& node : nodes)
			map[node.Name] = node;

		// From input testing:
		// All paths are cycling back to one step after the start after reaching the end,
		// therefore reaching the end repeatedly after the same step count:
		// 
		// (Start)                  (End)
		//    A ----> B ----> C ----> Z
		//            ^               |
		//            |_______________|

		// From all nodes ending with 'A', count steps from start to end for each of them
		uint64_t totalSteps = 1;
		for (const auto& node : nodes)
		{
			if (node.Name.ends_with('A'))
			{
				std::string currentNode = node.Name;
				auto dirIt = directions.begin();
				uint64_t steps = 0;

				while (!currentNode.ends_with('Z'))
				{
					currentNode = map[currentNode].GetNextNode(*dirIt);
					++dirIt;
					++steps;

					if (dirIt == directions.end())
						dirIt = directions.begin();
				}

				// Find least common multiple (lcm) of all step counts to find out
				// after how many steps all paths will reach the end at the same time:
				totalSteps = std::lcm(totalSteps, steps);
			}
		}

		return totalSteps;
	}
}
