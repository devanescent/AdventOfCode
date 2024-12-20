#include "Day18_RAMRun.h"
#include "GridMap.h"
#include <format>
#include <queue>
#include <map>

namespace AdventOfCode::Year2024::Day18
{
	RAMRun::RAMRun() : DayT(18, "RAM Run") { }

	struct MemoryProgress
	{
		Point<int> Position;
		uint64_t Distance;

		bool operator<(const MemoryProgress& other) const
		{
			return Distance > other.Distance;
		}
	};

	uint64_t FindShortestPath(const GridMap& memoryMap)
	{
		// Find shortest path:
		Point<int> start(0, 0);
		Point<int> end(memoryMap.Width() - 1, memoryMap.Height() - 1);

		uint64_t result = 0;

		// Remember visited points with shortest amount of steps reached
		std::map<Point<int>, uint64_t> visited;

		std::priority_queue<MemoryProgress> q;
		q.emplace(start, 0);

		while (!q.empty())
		{
			MemoryProgress progress = q.top();
			q.pop();

			if (progress.Position == end)
			{
				result = progress.Distance;
				break;
			}

			// Check if already visited
			auto visIt = visited.find(progress.Position);
			if (visIt != visited.end() && visIt->second <= progress.Distance)
				continue;
			else
				visited[progress.Position] = progress.Distance;

			// Try walking in every direction
			for (const auto& p : progress.Position.GetSurroundingPoints(false))
			{
				if (memoryMap.Contains(p) && memoryMap.Get(p) == '.')
					q.emplace(p, progress.Distance + 1);
			}
		}

		return result;
	}

	uint64_t RAMRun::ExecutePart1(std::vector<Point<int>> bytes)
	{
		std::vector<std::string> memory(_memorySize + 1, std::string(_memorySize + 1, '.'));
		GridMap memoryMap(std::move(memory));

		// Simulate bytes falling into the map:
		for (int i = 0; i < _simulationCount; ++i)
			memoryMap.Replace(bytes[i], '#');

		return FindShortestPath(memoryMap);
	}

	std::string RAMRun::ExecutePart2(std::vector<Point<int>> bytes)
	{
		std::vector<std::string> memory(_memorySize + 1, std::string(_memorySize + 1, '.'));
		GridMap memoryMap(std::move(memory));

		// Simulate bytes falling into the map:
		for (int i = 0; i < _simulationCount; ++i)
			memoryMap.Replace(bytes[i], '#');

		// Continue simulating falling blocks:
		Point<int> byteBlockingPath;
		for (int i = _simulationCount; i < bytes.size(); ++i)
		{
			memoryMap.Replace(bytes[i], '#');
			if (FindShortestPath(memoryMap) == 0)
			{
				byteBlockingPath = bytes[i];
				break;
			}
		}

		return std::format("{},{}", byteBlockingPath.X, byteBlockingPath.Y);
	}
}
