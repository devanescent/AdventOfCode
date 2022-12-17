#include "Day16_ProboscideaVolcanium.h"
#include <queue>
#include <set>

namespace AdventOfCode::Year2022::Day16
{
	struct PipeProgress
	{
		std::string CurrentValve;
		int TimeRemaining;
		int PressureReleased;
		std::set<std::string> OpenedValves;

		bool HasOpenedValve(const std::string& valve) const
		{
			return OpenedValves.find(valve) != OpenedValves.end();
		}

		PipeProgress OpenValve(std::string valve, int timeToOpen, int flow) const
		{
			int timeLeftAfterOpen = TimeRemaining - timeToOpen;
			std::set<std::string> openedValves = OpenedValves;
			openedValves.insert(valve);

			return PipeProgress
			{
				std::move(valve),
				timeLeftAfterOpen,
				PressureReleased + timeLeftAfterOpen * flow,
				std::move(openedValves)
			};
		}

		PipeProgress WaitUntilTimeout() const
		{
			return PipeProgress
			{
				CurrentValve,
				0,
				PressureReleased,
				OpenedValves
			};
		}

		// Order by priority: true means lower prio
		bool operator<(const PipeProgress& other) const
		{
			// Order by remaining time first, then by pressure released:
			if (TimeRemaining != other.TimeRemaining)
				return TimeRemaining < other.TimeRemaining;
			else
				return PressureReleased < other.PressureReleased;
		}
	};


	ProboscideaVolcanium::ProboscideaVolcanium() : DayT(16, "Proboscidea Volcanium") { }

	uint64_t ProboscideaVolcanium::ExecutePart1(std::map<std::string, Valve> valves)
	{
		std::priority_queue<PipeProgress> q;
		std::set<PipeProgress> visited;

		PipeProgress start{ "AA", 30, 0, { "AA" } };
		q.push(start); // Start at valve AA which has a flow of 0
		visited.insert(start);

		// Maps how long it takes from each valve to reach another valve:
		std::map<std::string, std::map<std::string, int>> connections;

		// Finds shortest path between two valves:
		auto getShortestConnection = [&](const Valve& fromV)
		{
			struct PathProgress
			{
				std::string Valve;
				int Distance;

				bool operator<(const PathProgress& other) const
				{
					return other.Distance < Distance;
				}
			};

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

		// Open valves:
		while (!q.empty() && q.top().TimeRemaining > 0)
		{
			// Find all possibilities to open a valve:
			PipeProgress pp = q.top();
			q.pop();

			bool canOpenAnotherValve = false;
			for (const auto& nextValve : connections.at(pp.CurrentValve))
			{
				// Skip itself and any valve with flow rate of 0:
				if (nextValve.first == pp.CurrentValve || valves[nextValve.first].FlowRate == 0)
					continue;

				// Skip valves that have been opened already:
				if (pp.HasOpenedValve(nextValve.first))
					continue;

				// Is there still enough time to open the valve?
				// (time required is distance + one minute to open the valve)
				// Time remaining must be larger for the valve to actually release any pressure
				int timeRequired = nextValve.second + 1;
				if (pp.TimeRemaining <= timeRequired)
					continue;

				canOpenAnotherValve = true;
				q.push(pp.OpenValve(nextValve.first, timeRequired, valves[nextValve.first].FlowRate));
			}

			// Otherwise, wait for the remaining time, if no other valve can be reached anymore:
			if (!canOpenAnotherValve)
				q.push(pp.WaitUntilTimeout());
		}

		return q.top().PressureReleased;
	}

	uint64_t ProboscideaVolcanium::ExecutePart2(std::map<std::string, Valve> valves)
	{
		return uint64_t();
	}
}
