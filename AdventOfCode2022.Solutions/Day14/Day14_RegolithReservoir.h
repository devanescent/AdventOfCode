#pragma once
#include "DayT.h"
#include "RockPathProcessor.h"
#include <map>

namespace AdventOfCode::Year2022::Day14
{
	// ---------------------------------------------------------------------------
	// Day14: Regolith Reservoir
	// ---------------------------------------------------------------------------
	class RegolithReservoir : public DayT<RockPathProcessor>
	{
	public:
		RegolithReservoir();

	protected:
		uint64_t ExecutePart1(std::vector<RockPath> rockPaths) override;
		uint64_t ExecutePart2(std::vector<RockPath> rockPaths) override;

	private:
		enum class GroundType
		{
			Sand,
			Rock
		};

		std::map<Point<int>, GroundType> m_groundStructure;
		int m_lowestRockLevel;

		void UpdateRockStructure(const RockPath& rocks);
		void MoveSandBlocks(bool checkFloor);
		uint64_t CountSandBlocks();
	};
}
