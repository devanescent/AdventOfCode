#include "CaveMap.h"

namespace AdventOfCode::Year2018::Day22
{
	CaveMap::CaveMap(size_t targetX, size_t targetY, size_t depth) :
		m_caveDepth(depth), m_targetX(targetX), m_targetY(targetY),
		m_erosionMap(targetY + 1, std::vector<uint64_t>(targetX + 1, 0)), m_caveRiskLevel(0)
	{
		// Calculate erosion levels:
		for (size_t y = 0; y <= targetY; ++y)
		{
			for (size_t x = 0; x <= targetX; ++x)
			{
				uint64_t erosionLevel = GetErosionLevel(x, y);

				// Update map:
				m_erosionMap[y][x] = erosionLevel;

				// Also, update total risk level:
				m_caveRiskLevel += (erosionLevel % 3);
			}
		}
	}

	uint64_t CaveMap::GetGeologicIndex(size_t x, size_t y)
	{
		if ((x == 0 && y == 0) || (x == m_targetX && y == m_targetY))
			return 0;
		else if (y == 0)
			return x * 16807;
		else if (x == 0)
			return y * 48271;
		else
			return m_erosionMap[y - 1][x] * m_erosionMap[y][x - 1];
	}

	uint64_t CaveMap::GetErosionLevel(size_t x, size_t y)
	{
		return (GetGeologicIndex(x, y) + m_caveDepth) % 20183;
	}
}
