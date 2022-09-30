#pragma once
#include "Unit.h"

#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AdventOfCode::Year2018::Day15
{
	// Comparator for ordering coordinates in "reading order":
	class ReadingOrder
	{
	public:
		bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
		{
			if (lhs.second != rhs.second)
				return lhs.second < rhs.second;
			else
				return lhs.first < rhs.first;
		}
	};

	// Collection of all units with their coordinate, ordered by reading order
	using UnitMap = std::map<std::pair<int, int>, Unit, ReadingOrder>;

	class Battle
	{
	public:
		struct BattleResult
		{
			int CompletedRounds;
			int NumberOfElvesAlive;
			int NumberOfGoblinsAlive;
			int TotalHitpointsOfRemainingUnits;

			int GetOutcome() { return CompletedRounds * TotalHitpointsOfRemainingUnits; }
		};

		Battle(const std::vector<std::string>& map);
		BattleResult ExecuteCombat();
		int GetUnitCount(Unit::UnitType type);
		void IncreaseElvesAttackPower(int increment);

	private:
		// During the search for a target, keep track of explored coordinates in the cave
		struct FindTargetProgress
		{
			int X, Y;
			int MovedDistance;
			std::pair<int, int> FirstStep; // First step taken to reach this position

			FindTargetProgress(int x, int y, int movedDistance, std::pair<int, int> firstStep);
			bool operator<(const FindTargetProgress& other) const;
		};

		// Controls how / when a unit attempts to move
		// -> remember, so that units that found no target during last will not attempt again 
		//    until another unit moved or died (i.e. the battlefield has changed)
		enum class UnitMoveState
		{
			NotMovedYet, // Unit can still move this turn
			Moved,       // Unit has already moved
			CouldNotMove // Unit could not move and will not attempt again unless the battlefield has changed
		};

		const std::vector<std::string>& m_map;
		UnitMap m_units;
		std::map<Unit::UnitType, int> m_unitCounts;
		std::map<std::pair<int, int>, UnitMoveState> m_unitMoveStates;

		bool IsBattleContinued();

		void UpdateUnitMoveStates(bool hasBattleFieldChanged);
		bool CanUnitMoveThisTurn(int x, int y, bool hasBattleFieldChanged);
		bool IsEnemyTargetAvailable(Unit::UnitType attackerType);
		bool ExecuteAttack(const Unit& attacker, UnitMap::iterator defender);

		std::optional<std::pair<int, int>> GetNextMove(int x, int y, Unit::UnitType attackerType);
		UnitMap::iterator FindTarget(int x, int y, Unit::UnitType attackerType, UnitMap::iterator currentTarget);
		UnitMap::iterator GetAdjacentTarget(int x, int y, Unit::UnitType attackerType);
		std::vector<std::pair<int, int>> GetAdjacentCoords(int x, int y);
	};
}