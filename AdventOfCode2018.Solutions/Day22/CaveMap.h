#pragma once
#include <vector>

namespace AdventOfCode::Year2018::Day22
{
	enum class RiskLevel
	{
		Rocky = 0,
		Wet = 1,
		Narrow = 2
	};

	enum class Tool
	{
		Torch,
		ClimbingGear,
		None
	};

	// A single coordinate inside the cave
	struct CaveTile
	{
		int ErosionLevel;
		RiskLevel Risk;

		CaveTile(int erosionLvl, RiskLevel risk) : 
			ErosionLevel(erosionLvl), Risk(risk) {}
	};

	// Records progress during exploration of the cave
	struct CaveProgress
	{
		// Position inside the cave and risk level at that position
		int X;
		int Y;
		RiskLevel Risk;

		// Minutes spent to reach this point
		int MinutesSpent;

		// Tool currently equiped at this point
		Tool CurrentTool;

		// How far away the target is from this position (relevant for prioritizing progress points)
		int DistanceToTarget;

		CaveProgress(int x, int y, RiskLevel risk, int minutes, int distToTarget, Tool tool) :
			X(x), Y(y), Risk(risk), MinutesSpent(minutes), DistanceToTarget(distToTarget), CurrentTool(tool) {}

		// Ordering progress points during exploration:
		// true means, this progress point is lower priority than the other progress point
		bool operator<(const CaveProgress& other) const
		{
			// Order by (estimated) time to goal
			return (MinutesSpent + DistanceToTarget) > (other.MinutesSpent + other.DistanceToTarget);

			//// 1) Order by Time: More time spent equals lower priority:
			//if (MinutesSpent != other.MinutesSpent)
			//	return MinutesSpent > other.MinutesSpent;
			//else
			//{
			//	// 2) Otherwise, order by distance to target: Higher distance equals lower priority:
			//	return DistanceToTarget > other.DistanceToTarget;
			//}
		}
	};


	class CaveMap
	{
	public:
		CaveMap(int targetX, int targetY, int depth);
		
		// Gets the tile at the given coordinates; increases map size if necessary
		const CaveTile& GetCaveTile(int x, int y);

		// Sum up the risk level from the mouth of the cave up to the target position:
		uint64_t GetCaveRiskLevel();

		// During exploration, return possible progress points from the given location:
		std::vector<CaveProgress> GetPossiblePaths(const CaveProgress& currentProgress);

	private:
		int m_caveDepth;
		int m_targetX;
		int m_targetY;
		int m_mapWidth;
		int m_mapHeight;
		std::vector<std::vector<CaveTile>> m_map;

		int GetGeologicIndex(int x, int y);
		int GetErosionLevel(int x, int y);

		// Get the progress point when moving to the given position
		CaveProgress Move(const CaveProgress& currentPos, int nextX, int nextY, const CaveTile& nextPos);
	};
}