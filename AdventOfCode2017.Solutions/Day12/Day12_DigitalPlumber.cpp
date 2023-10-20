#include "Day12_DigitalPlumber.h"
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>

namespace AdventOfCode::Year2017::Day12
{
	DigitalPlumber::DigitalPlumber() : DayT(12, "Digital Plumber") { }

	uint64_t DigitalPlumber::ExecutePart1(std::vector<Pipe> pipes)
	{
		// To map:
		std::map<int, const Pipe*> pipeMap;

		for (const Pipe& p : pipes)
			pipeMap[p.ProgramId] = &p;
		
		// BFS to find all (directly and indirectly connected) programs:
		std::unordered_set<int> visited;
		std::queue<const Pipe*> bfsQueue;
		bfsQueue.push(pipeMap[0]);

		while (!bfsQueue.empty())
		{
			const Pipe* p = bfsQueue.front();
			bfsQueue.pop();
			visited.insert(p->ProgramId);

			for (auto connection : p->ConnectedTo)
			{
				if (!visited.contains(connection))
					bfsQueue.push(pipeMap[connection]);
			}
		}

		return visited.size();
	}

	uint64_t DigitalPlumber::ExecutePart2(std::vector<Pipe> pipes)
	{
		return uint64_t();
	}
}
