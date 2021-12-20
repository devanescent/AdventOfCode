#pragma once

namespace AdventOfCode::Year2021::Day15
{
	class CavePosition
	{
	public:
		CavePosition(int x, int y, uint64_t totalRisk) :
			XPos(x), YPos(y), TotalRiskSoFar(totalRisk) {}

		const int XPos; // X-Coord of this position
		const int YPos; // Y-Coord of this position

		uint64_t TotalRiskSoFar; // total risk so far up to this point

		// Sort by "distance", otherwise prefer positions further away
		bool operator<(const CavePosition& other) const
		{
			if (TotalRiskSoFar != other.TotalRiskSoFar)
				return TotalRiskSoFar < other.TotalRiskSoFar;
			else if (XPos != other.XPos)
				return XPos > other.XPos;
			else
				return YPos > other.YPos;
		}
	};
}