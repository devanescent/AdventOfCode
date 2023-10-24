#include "Day22_SporificaVirus.h"
#include <map>

namespace AdventOfCode::Year2017::Day22
{
	SporificaVirus::SporificaVirus() : DayTC(22, "Sporifica Virus") { }

	uint64_t SporificaVirus::ExecutePart1(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos)
	{
		// Current direction:
		int dx = 0, dy = -1;

		std::map<Point<int>, bool> infectedNodes;
		for (const Point<int>& p : initialInfectedNodes)
			infectedNodes[p] = true;

		// Execute bursts:
		uint64_t infectionsCaused = 0;

		for (int i = 0; i < 10'000; ++i)
		{
			auto infectedNodeIt = infectedNodes.find(carrierPos);

			if (infectedNodeIt != infectedNodes.end() && infectedNodeIt->second)
			{
				// Current node infected: turn right
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

				infectedNodeIt->second = false;
			}
			else
			{
				// Otherwise, turn left
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

				if (infectedNodeIt != infectedNodes.end())
					infectedNodeIt->second = true;
				else
					infectedNodes[carrierPos] = true;
				++infectionsCaused;
			}
			
			// Move carrier:
			carrierPos = carrierPos.MoveBy(dx, dy);
		}

		return infectionsCaused;
	}

	uint64_t SporificaVirus::ExecutePart2(std::vector<Point<int>> initialInfectedNodes, Point<int> carrierPos)
	{
		return uint64_t();
	}
}
