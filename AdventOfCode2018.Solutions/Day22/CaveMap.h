#pragma once
#include <vector>

namespace AdventOfCode::Year2018::Day22
{
	class CaveMap
	{
	public:
		CaveMap(size_t targetX, size_t targetY, size_t depth);
		uint64_t GetRiskLevel() { return m_caveRiskLevel; }

	private:
		enum class RiskLevel
		{
			Rocky = 0,
			Wet = 1,
			Narrow = 2
		};

		std::vector<std::vector<uint64_t>> m_erosionMap;
		size_t m_caveDepth;
		size_t m_targetX;
		size_t m_targetY;
		uint64_t m_caveRiskLevel;

		uint64_t GetGeologicIndex(size_t x, size_t y);
		uint64_t GetErosionLevel(size_t x, size_t y);
	};
}