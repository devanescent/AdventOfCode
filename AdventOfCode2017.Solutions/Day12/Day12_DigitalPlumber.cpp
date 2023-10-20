#include "Day12_DigitalPlumber.h"
#include <algorithm>
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
		return FindGroup(0, pipeMap);
	}

	uint64_t DigitalPlumber::ExecutePart2(std::vector<Pipe> pipes)
	{
		// To map:
		std::map<int, const Pipe*> pipeMap;
		for (const Pipe& p : pipes)
			pipeMap[p.ProgramId] = &p;

		uint64_t grpCount = 0;
		while (!pipeMap.empty())
		{
			if (FindGroup(pipeMap.begin()->first, pipeMap) > 0)
				++grpCount;
		}

		return grpCount;
	}

	uint64_t DigitalPlumber::FindGroup(int programId, std::map<int, const Pipe*>& pipeMap)
	{
		std::queue<const Pipe*> bfsQueue;
		bfsQueue.push(pipeMap[programId]);
		pipeMap.erase(0);

		uint64_t grpSize = 0;
		while (!bfsQueue.empty())
		{
			++grpSize;

			const Pipe* p = bfsQueue.front();
			bfsQueue.pop();

			for (auto connection : p->ConnectedTo)
			{
				auto nextPipe = pipeMap.find(connection);
				if (nextPipe != pipeMap.end())
				{
					bfsQueue.push(nextPipe->second);
					pipeMap.erase(nextPipe->first);
				}
			}
		}

		return grpSize;
	}
}
