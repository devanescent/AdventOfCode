#include "CaveMap.h"
#include <cmath>

namespace AdventOfCode::Year2018::Day22
{
	CaveMap::CaveMap(int targetX, int targetY, int depth) :
		m_caveDepth(depth), m_targetX(targetX), m_targetY(targetY),
		m_mapWidth(targetX + 1), m_mapHeight(targetY + 1),
		m_map(m_mapHeight, std::vector<CaveTile>(m_mapWidth, CaveTile(0,RiskLevel::Rocky)))
	{
		// Calculate erosion levels:
		// (build map a little larger than target coordinates):
		for (int y = 0; y <= targetY; ++y)
		{
			for (int x = 0; x <= targetX; ++x)
			{
				int erosionLevel = GetErosionLevel(x, y);
				RiskLevel risk = static_cast<RiskLevel>(erosionLevel % 3);

				// Update map:
				m_map[y][x] = CaveTile(erosionLevel, risk);
			}
		}
	}

	const CaveTile& CaveMap::GetCaveTile(int mapX, int mapY)
	{
		// Add row(s):
		if (m_mapHeight <= mapY)
		{
			for (int y = m_mapHeight; y <= mapY; ++y)
			{
				m_map.emplace_back(std::vector<CaveTile>());
				for (int x = 0; x < m_mapWidth; ++x)
				{
					int erosionLevel = GetErosionLevel(x, y);
					RiskLevel risk = static_cast<RiskLevel>(erosionLevel % 3);
					m_map[y].emplace_back(CaveTile(erosionLevel, risk));
				}
			}
			m_mapHeight = mapY + 1;
		}
		
		// Add column:
		if (m_mapWidth <= mapX)
		{
			for (int y = 0; y < m_mapHeight; ++y)
			{
				for (int x = m_mapWidth; x <= mapX; ++x)
				{
					int erosionLevel = GetErosionLevel(x, y);
					RiskLevel risk = static_cast<RiskLevel>(erosionLevel % 3);
					m_map[y].emplace_back(CaveTile(erosionLevel, risk));
				}
			}
			m_mapWidth = mapX + 1;
		}
		
		return m_map[mapY][mapX];
	}

	uint64_t CaveMap::GetCaveRiskLevel()
	{
		uint64_t totalRiskLevel = 0;

		for (size_t y = 0; y <= m_targetY; ++y)
			for (size_t x = 0; x <= m_targetX; ++x)
				totalRiskLevel += static_cast<int>(m_map[y][x].Risk);

		return totalRiskLevel;
	}

	std::vector<CaveProgress> CaveMap::GetPossiblePaths(const CaveProgress& currentProgress)
	{
		std::vector<CaveProgress> progressOptions;

		int x = currentProgress.X;
		int y = currentProgress.Y;

		// Move left:
		if (x > 0)
			progressOptions.emplace_back(Move(currentProgress, x - 1, y, GetCaveTile(x - 1, y)));

		// Move top:
		if (y > 0)
			progressOptions.emplace_back(Move(currentProgress, x, y - 1, GetCaveTile(x, y - 1)));

		// Move right:
		progressOptions.emplace_back(Move(currentProgress, x + 1, y, GetCaveTile(x + 1, y)));

		// Move down:
		progressOptions.emplace_back(Move(currentProgress, x, y + 1, GetCaveTile(x, y + 1)));

		return progressOptions;
	}

	int CaveMap::GetGeologicIndex(int x, int y)
	{
		if ((x == 0 && y == 0) || (x == m_targetX && y == m_targetY))
			return 0;
		else if (y == 0)
			return static_cast<int>(x * 16807);
		else if (x == 0)
			return static_cast<int>(y * 48271);
		else
			return m_map[y - 1][x].ErosionLevel * m_map[y][x - 1].ErosionLevel;
	}

	int CaveMap::GetErosionLevel(int x, int y)
	{
		return (GetGeologicIndex(x, y) + m_caveDepth) % 20183;
	}

	CaveProgress CaveMap::Move(const CaveProgress& currentPos, int nextX, int nextY, const CaveTile& nextPos)
	{
		int distToTarget = std::abs(m_targetX - nextX) + std::abs(m_targetY - nextY);
		int minutes = 1; // Moving to an adjacent region takes one minute.
		Tool nextTool = currentPos.CurrentTool;

		// RULES:
		// 
		// Tools can only be used in certain regions:
		// - In rocky regions, you can use the climbing gear or the torch. You cannot use neither (you'll likely slip and fall).
		// - In wet regions, you can use the climbing gear or neither tool. You cannot use the torch (if it gets wet, you won't have a light source).
		// - In narrow regions, you can use the torch or neither tool. You cannot use the climbing gear (it's too bulky to fit).
		// 
		// Movement in one direction is therefore only possible, if either the risk level is the same as the current tile
		// or if the tool can be changed. In case of a tool change, only the following paths are possible:
		// - Rocky <-> Narrow by using a torch
		// - Narrow <-> Wet by using neither tool
		// - Wet <-> Rocky by using the climbing gear

		// If risk level at new position differs from current risk level, a tool change might be neccessary:
		if (currentPos.Risk != nextPos.Risk)
		{
			switch (nextPos.Risk)
			{
				// Move to rocky tile:
				case RiskLevel::Rocky:
				{
					if (currentPos.CurrentTool == Tool::None)
					{
						minutes += 7; // must change tool
						if (currentPos.Risk == RiskLevel::Narrow)
							nextTool = Tool::Torch;
						else
							nextTool = Tool::ClimbingGear;
					}
					break;
				}
				// Move to narrow tile:
				case RiskLevel::Narrow:
				{
					if (currentPos.CurrentTool == Tool::ClimbingGear)
					{
						minutes += 7; // must change tool
						if (currentPos.Risk == RiskLevel::Rocky)
							nextTool = Tool::Torch;
						else
							nextTool = Tool::None;
					}
					break;
				}
				// Move to wet tile:
				case RiskLevel::Wet:
				{
					if (currentPos.CurrentTool == Tool::Torch)
					{
						minutes += 7; // must change tool
						if (currentPos.Risk == RiskLevel::Rocky)
							nextTool = Tool::ClimbingGear;
						else
							nextTool = Tool::None;
					}
					break;
				}
			}
		}

		// At the target the torch needs to be equiped, which might require yet another tool change:
		if (nextX == m_targetX && nextY == m_targetY && nextTool != Tool::Torch)
		{
			minutes += 7;
			nextTool = Tool::Torch;
		}

		return CaveProgress(nextX, nextY, nextPos.Risk, currentPos.MinutesSpent + minutes, distToTarget, nextTool);
	}
}
