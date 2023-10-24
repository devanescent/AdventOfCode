#include "Day22_SporificaVirus.h"
#include <map>

namespace AdventOfCode::Year2017::Day22
{
	SporificaVirus::SporificaVirus() : DayTC(22, "Sporifica Virus") { }

	void TurnRight(int& dx, int& dy)
	{
		if (dx == 0)
		{
			dx = -dy;
			dy = 0;
		}
		else if (dy == 0)
		{
			dy = dx;
			dx = 0;
		}
	}

	void TurnLeft(int& dx, int& dy)
	{
		if (dx == 0)
		{
			dx = dy;
			dy = 0;
		}
		else if (dy == 0)
		{
			dy = -dx;
			dx = 0;
		}
	}

	void ReverseDirection(int& dx, int& dy)
	{
		dx = -dx;
		dy = -dy;
	}

	uint64_t SporificaVirus::ExecutePart1(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos)
	{
		// Current direction:
		int dx = 0, dy = -1;

		std::map<Point<int>, NodeState> infectedNodes;
		for (const Point<int>& p : initialInfectedNodes)
			infectedNodes[p] = NodeState::Infected;

		// Execute bursts:
		uint64_t infectionsCaused = 0;

		for (int i = 0; i < 10'000; ++i)
		{
			auto infectedNodeIt = infectedNodes.find(carrierPos);
			if (infectedNodeIt == infectedNodes.end())
			{
				// Clean node:
				TurnLeft(dx, dy);
				infectedNodes[carrierPos] = NodeState::Infected;
				++infectionsCaused;
			}
			else if (infectedNodeIt->second == NodeState::Infected)
			{
				// Infected node:
				TurnRight(dx, dy);
				infectedNodeIt->second = NodeState::Clean;
			}
			else
			{
				// Node that was cleaned but is infected again:
				TurnLeft(dx, dy);
				infectedNodeIt->second = NodeState::Infected;
				++infectionsCaused;
			}
			
			// Move carrier:
			carrierPos = carrierPos.MoveBy(dx, dy);
		}

		return infectionsCaused;
	}

	uint64_t SporificaVirus::ExecutePart2(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos)
	{
		// Current direction:
		int dx = 0, dy = -1;

		std::map<Point<int>, NodeState> infectedNodes;
		for (const Point<int>& p : initialInfectedNodes)
			infectedNodes[p] = NodeState::Infected;

		// Execute bursts:
		uint64_t infectionsCaused = 0;

		for (int i = 0; i < 10'000'000; ++i)
		{
			auto infectedNodeIt = infectedNodes.find(carrierPos);
			if (infectedNodeIt == infectedNodes.end())
			{
				// Clean node:
				TurnLeft(dx, dy);
				infectedNodes[carrierPos] = NodeState::Weakened;
			}
			else
			{
				switch (infectedNodeIt->second)
				{
					case NodeState::Clean:
						TurnLeft(dx, dy);
						break;
					case NodeState::Weakened:
						// does not turn
						++infectionsCaused;
						break;
					case NodeState::Infected:
						TurnRight(dx, dy);
						break;
					case NodeState::Flagged:
						ReverseDirection(dx, dy);
						break;
				}

				// set next state:
				infectedNodeIt->second = static_cast<NodeState>((static_cast<int>(infectedNodeIt->second) + 1) % 4);
			}

			// Move carrier:
			carrierPos = carrierPos.MoveBy(dx, dy);
		}

		return infectionsCaused;
	}
}
