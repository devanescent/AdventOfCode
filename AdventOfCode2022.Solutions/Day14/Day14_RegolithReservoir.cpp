#include "Day14_RegolithReservoir.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2022::Day14
{
	RegolithReservoir::RegolithReservoir() : DayT(14, "Regolith Reservoir"), m_lowestRockLevel(0) { }

	void RegolithReservoir::UpdateRockStructure(const RockPath& rocks)
	{
		// Add first point from path directly:
		m_groundStructure[rocks.Path[0]] = GroundType::Rock;

		// Keep track of the lowest rock level:
		m_lowestRockLevel = std::max(m_lowestRockLevel, rocks.Path[0].Y);

		for (int i = 1; i < rocks.Path.size(); ++i)
		{
			m_lowestRockLevel = std::max(m_lowestRockLevel, rocks.Path[i].Y);

			int dx = rocks.Path[i - 1].X - rocks.Path[i].X;
			int dy = rocks.Path[i - 1].Y - rocks.Path[i].Y;

			// Iterate over each segment given by two points:
			// (without the endpoint, as this was inserted by the previous segment)
			if (dx == 0)
			{
				// Vertical line:
				int dyStep = dy / std::abs(dy);
				for (int y = 0; y != dy; y += dyStep)
				{
					m_groundStructure[rocks.Path[i].MoveYBy(y)] = GroundType::Rock;
				}
			}
			else if (dy == 0)
			{
				// Horizontal line:
				int dxStep = dx / std::abs(dx);
				for (int x = 0; x != dx; x += dxStep)
				{
					m_groundStructure[rocks.Path[i].MoveXBy(x)] = GroundType::Rock;
				}
			}
		}
	}

	void RegolithReservoir::MoveSandBlocks(bool checkFloor)
	{
		Point sandStart{ 500,0 };
		bool startPointBlocked = false;
		bool aboveAbyss = true;

		while (!startPointBlocked && aboveAbyss)
		{
			// Create a new point of sand and start moving down:
			Point currentSandPos = sandStart;
			bool sandIsMoving = true;

			while (sandIsMoving)
			{
				// Check if abyss has been reached (only if floor is ignored):
				if (!checkFloor && currentSandPos.Y >= m_lowestRockLevel)
				{
					aboveAbyss = false;
					break;
				}
				// Check if floor has been reached (only if floor is checked):
				else if (checkFloor && currentSandPos.Y == m_lowestRockLevel + 1)
				{
					// Sand comes to rest on the ground:
					m_groundStructure[currentSandPos] = GroundType::Sand;
					sandIsMoving = false;
				}
				// Check below first...
				else if (m_groundStructure.find(currentSandPos.MoveYBy(1)) == m_groundStructure.end())
				{
					currentSandPos = currentSandPos.MoveYBy(1);
				}
				// ... then below-left ...
				else if (m_groundStructure.find(currentSandPos.MoveBy(-1, 1)) == m_groundStructure.end())
				{
					currentSandPos = currentSandPos.MoveBy(-1, 1);
				}
				// ... then below-right ...
				else if (m_groundStructure.find(currentSandPos.MoveBy(1, 1)) == m_groundStructure.end())
				{
					currentSandPos = currentSandPos.MoveBy(1, 1);
				}
				// ... otherwise the sand comes to rest
				else
				{
					m_groundStructure[currentSandPos] = GroundType::Sand;
					sandIsMoving = false;

					if (currentSandPos == sandStart)
						startPointBlocked = true;
				}
			}
		}
	}

	uint64_t RegolithReservoir::CountSandBlocks()
	{
		return std::count_if(m_groundStructure.begin(), m_groundStructure.end(),
			[](const auto& ground) { return ground.second == GroundType::Sand; }
		);
	}

	uint64_t RegolithReservoir::ExecutePart1(std::vector<RockPath> rockPaths)
	{
		m_groundStructure.clear();
		m_lowestRockLevel = 0;

		// Map all points where there is rock:
		for (const RockPath& rocks : rockPaths)
			UpdateRockStructure(rocks);

		// Move the sand blocks:
		MoveSandBlocks(false);
		return CountSandBlocks();
	}

	uint64_t RegolithReservoir::ExecutePart2(std::vector<RockPath> rockPaths)
	{
		m_groundStructure.clear();
		m_lowestRockLevel = 0;

		// Map all points where there is rock:
		for (const RockPath& rocks : rockPaths)
			UpdateRockStructure(rocks);

		// Move the sand blocks:
		MoveSandBlocks(true);
		return CountSandBlocks();
	}
}
