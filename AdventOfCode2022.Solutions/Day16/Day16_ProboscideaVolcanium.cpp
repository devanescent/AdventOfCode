#include "Day16_ProboscideaVolcanium.h"
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <vector>

namespace AdventOfCode::Year2022::Day16
{
	ProboscideaVolcanium::ProboscideaVolcanium() : DayT(16, "Proboscidea Volcanium") { }

	struct PipeProgress
	{
		std::string CurrentValve;
		int TimeRemaining;
		int PressureReleased;
		std::vector<std::string> OpenedValves;

		bool HasOpenedValve(const std::string& valve) const
		{
			return std::find(OpenedValves.begin(), OpenedValves.end(), valve) != OpenedValves.end();
		}

		PipeProgress OpenValve(std::string valve, int timeToOpen, int flow) const
		{
			int timeLeftAfterOpen = TimeRemaining - timeToOpen;
			std::vector<std::string> openedValves = OpenedValves;
			openedValves.push_back(valve);

			return PipeProgress
			{
				std::move(valve),
				timeLeftAfterOpen,
				PressureReleased + timeLeftAfterOpen * flow,
				std::move(openedValves)
			};
		}
	};

	using PipeConnections = std::map<std::string, std::map<std::string, int>>;

	// Build connections between all valves:
	// Maps how long it takes from each valve to reach any other valve
	PipeConnections BuildConnections(const std::map<std::string, Valve>& valves)
	{
		PipeConnections connections;

		struct PathProgress
		{
			std::string Valve;
			int Distance;

			bool operator<(const PathProgress& other) const
			{
				return other.Distance < Distance;
			}
		};

		// Finds shortest path between two valves:
		auto getShortestConnection = [&](const Valve& fromV)
		{
			std::priority_queue<PathProgress> q;
			q.emplace(fromV.Name, 0);

			while (!q.empty())
			{
				PathProgress pp = q.top();
				q.pop();

				for (const std::string& con : valves.at(pp.Valve).ConnectedValves)
				{
					if (con == fromV.Name)
					{
						connections[fromV.Name][con] = 0;
						continue;
					}

					int d = pp.Distance + 1;
					auto prevDistance = connections[fromV.Name].find(con);

					if (prevDistance != connections[fromV.Name].end() && prevDistance->second <= d)
						continue;
					else
					{
						connections[fromV.Name][con] = d;
						q.emplace(con, d);
					}
				}
			}
		};

		// Fill map:
		for (const auto& valve : valves)
		{
			getShortestConnection(valve.second);
		}

		// Remove valves with flow rate of zero (except the starting valve "AA"):
		std::erase_if(connections, [&](const auto& con) { return con.first != "AA" && valves.at(con.first).FlowRate == 0; });

		// Remove all connection to self and to valves with flowrate of zero:
		for (auto& cons : connections)
		{
			const std::string& thisValve = cons.first;
			std::erase_if(cons.second, [&](const auto& con) { return con.first == thisValve || valves.at(con.first).FlowRate == 0; });
		}

		return connections;
	}

	// Get maximum pressure that can be released with the given set of valid valves:
	uint64_t GetMaxReleasedPressure(const std::map<std::string, Valve>& valves, const PipeConnections& cons, const std::set<std::string>& validValves, int time)
	{
		// DFS
		std::stack<PipeProgress> s;

		PipeProgress start{ "AA", time, 0, { "AA" } };
		s.push(start);

		// Open valves (only valves contained in the valid set):
		uint64_t bestResult = 0;
		while (!s.empty())
		{
			// Find all possibilities to open a valve:
			PipeProgress pp = s.top();
			s.pop();

			bool canOpenAnotherValve = false;
			for (const auto& nextValve : cons.at(pp.CurrentValve))
			{
				// Skip valves that have been opened already or that are not allowed to be visited:
				if (pp.HasOpenedValve(nextValve.first) || !validValves.contains(nextValve.first))
					continue;

				// Is there still enough time to open the valve? (time required is distance + one minute to open the valve)
				int timeRequired = nextValve.second + 1;

				// Time remaining must be larger for the valve to actually release any pressure
				if (pp.TimeRemaining <= timeRequired)
					continue;

				canOpenAnotherValve = true;
				s.push(pp.OpenValve(nextValve.first, timeRequired, valves.at(nextValve.first).FlowRate));
			}

			// Otherwise, wait for the remaining time, if no other valve can be reached anymore or all valves are opened:
			if (!canOpenAnotherValve)
			{
				auto result = pp.PressureReleased;
				bestResult = result > bestResult ? result : bestResult;
			}
		}

		return bestResult;
	}

	// Split set of valves into two halves:
	using ValveSplit = std::pair<std::set<std::string>, std::set<std::string>>;

	void FindAllSplitsRecursive(std::vector<ValveSplit>& splits, const std::vector<std::string>& allValves, std::set<std::string> currentSubset, std::vector<std::string>::const_iterator nextValve)
	{
		auto reqSize = allValves.size() / 2;

		if (currentSubset.size() == reqSize)
		{
			// Remaining elements not in the current subset:
			std::set<std::string> remainingValves;
			std::set_difference(allValves.begin(), allValves.end(), currentSubset.begin(), currentSubset.end(),
				std::inserter(remainingValves, remainingValves.end()));

			splits.emplace_back(currentSubset, remainingValves);
		}
		else
		{
			while (nextValve != allValves.end() && currentSubset.size() + (allValves.end() - nextValve) >= reqSize)
			{
				std::set<std::string> subset = currentSubset;
				subset.insert(*nextValve);
				++nextValve;

				FindAllSplitsRecursive(splits, allValves, std::move(subset), nextValve);
			}
		}
	}

	std::vector<ValveSplit> FindAllSplits(const std::vector<std::string>& allValves)
	{
		std::vector<ValveSplit> splits;
		FindAllSplitsRecursive(splits, allValves, {}, allValves.begin());
		return splits;
	}

	uint64_t ProboscideaVolcanium::ExecutePart1(std::map<std::string, Valve> valves)
	{
		auto connections = BuildConnections(valves);

		// Open valves (use all valves):
		std::set<std::string> validValves;
		std::transform(connections.begin(), connections.end(), std::inserter(validValves, validValves.end()),
			[](const auto& valve) { return valve.first; });

		return GetMaxReleasedPressure(valves, connections, validValves, 30);
	}

	uint64_t ProboscideaVolcanium::ExecutePart2(std::map<std::string, Valve> valves)
	{
		auto connections = BuildConnections(valves);

		std::vector<std::string> allValves;
		std::transform(connections.begin(), connections.end(), std::back_inserter(allValves),
			[](const auto& valve) { return valve.first; });

		// Find all possibilities to split the set of valves in two halves:
		std::vector<ValveSplit> splits = FindAllSplits(allValves);

		uint64_t bestResult = 0;
		for (const ValveSplit& split : splits)
		{
			uint64_t result = GetMaxReleasedPressure(valves, connections, split.first, 26) + GetMaxReleasedPressure(valves, connections, split.second, 26);
			bestResult = result > bestResult ? result : bestResult;
		}

		return bestResult;
	}
}
