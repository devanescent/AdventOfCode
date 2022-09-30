#include "Battle.h"
#include <numeric>
#include <queue>

namespace AdventOfCode::Year2018::Day15
{
	Battle::FindTargetProgress::FindTargetProgress(int x, int y, int movedDistance, std::pair<int, int> firstStep) :
		X(x), Y(y), MovedDistance(movedDistance), FirstStep(firstStep)
	{}

	bool Battle::FindTargetProgress::operator<(const FindTargetProgress& other) const
	{
		// Returning true means this element has lower priority than the other element:
		// the higher the distance traveled, the lower the priority
		if (MovedDistance != other.MovedDistance)
			return MovedDistance > other.MovedDistance;
		else if (Y != other.Y)
			return Y > other.Y;
		else if (X != other.X)
			return X > other.X;
		else if (FirstStep.second != other.FirstStep.second)
			return FirstStep.second > other.FirstStep.second;
		else
			return FirstStep.first > other.FirstStep.first;
	}

	Battle::Battle(const std::vector<std::string>& map) : m_map(map)
	{
		// Process the map: Collect all units on the battlefield:
		for (int y = 0; y < map.size(); ++y)
		{
			for (int x = 0; x < map[y].length(); ++x)
			{
				char c = map[y][x];
				if (c == 'E' || c == 'G')
				{
					Unit::UnitType t = static_cast<Unit::UnitType>(c);
					m_units.emplace(std::make_pair<std::pair<int, int>, Unit>({ x, y }, Unit(t)));
					++m_unitCounts[t];
				}
			}
		}
	}

	// Battle continues until units of one side are eliminated
	bool Battle::IsBattleContinued()
	{
		return m_unitCounts.at(Unit::UnitType::Elf) > 0 && m_unitCounts.at(Unit::UnitType::Goblin) > 0;
	}

	// At the start of each round, update move states
	void Battle::UpdateUnitMoveStates(bool hasBattleFieldChanged)
	{
		for (auto& x : m_unitMoveStates)
		{
			// A unit that moved during the last turn can move again this turn, 
			// as well as units that could not move but the battlefield has changed at the end of the last turn
			if (x.second == UnitMoveState::Moved || x.second == UnitMoveState::CouldNotMove && hasBattleFieldChanged)
				x.second = UnitMoveState::NotMovedYet;
		}
	}

	// Check if the current unit at the given coordinates attempts to move this turn
	bool Battle::CanUnitMoveThisTurn(int x, int y, bool hasBattleFieldChanged)
	{
		auto unitLastMoveState = m_unitMoveStates.find({ x, y });

		return
			// Unit can move if either...
			unitLastMoveState == m_unitMoveStates.end() || // Unit has not taken a turn yet
			unitLastMoveState->second == UnitMoveState::NotMovedYet || // Unit has not already moved
			unitLastMoveState->second == UnitMoveState::CouldNotMove && hasBattleFieldChanged; // Unit could not move the last time and the battle field has changed since
	}

	bool Battle::IsEnemyTargetAvailable(Unit::UnitType attackerType)
	{
		return
			attackerType == Unit::UnitType::Elf && m_unitCounts.at(Unit::UnitType::Goblin) > 0 ||
			attackerType == Unit::UnitType::Goblin && m_unitCounts.at(Unit::UnitType::Elf) > 0;
	}

	// Return true, if the defender was killed
	bool Battle::ExecuteAttack(const Unit& attacker, UnitMap::iterator defender)
	{
		// Attack directly without moving:
		attacker.Attack(defender->second);

		// Remove dead units from fight:
		if (!defender->second.IsAlive())
		{
			--m_unitCounts[defender->second.GetUnitType()];
			m_unitMoveStates.erase(defender->first);
			m_units.erase(defender);
			return true;
		}
		else
			return false;
	}

	std::optional<std::pair<int, int>> Battle::GetNextMove(int x, int y, Unit::UnitType attackerType)
	{
		std::priority_queue<FindTargetProgress> prioQ;
		std::map<std::pair<int, int>, int> visited;

		prioQ.emplace(FindTargetProgress(x, y, 0, { -1, -1 }));
		visited[{x, y}] = 0;

		auto target = m_units.end();
		while (!prioQ.empty() && (target = GetAdjacentTarget(prioQ.top().X, prioQ.top().Y, attackerType)) == m_units.end())
		{
			// Get current top item:
			auto top = prioQ.top();
			prioQ.pop();

			// Get potential next moves:
			for (auto&& coord : GetAdjacentCoords(top.X, top.Y))
			{
				auto visIt = visited.find(coord);
				if (visIt == visited.end() || visIt->second > top.MovedDistance + 1)
				{
					auto firstStep = top.FirstStep == std::pair<int, int>(-1, -1) ? coord : top.FirstStep;
					prioQ.emplace(FindTargetProgress(coord.first, coord.second, top.MovedDistance + 1, firstStep));

					// Update visited list:
					if (visIt == visited.end())
						visited.emplace(coord, top.MovedDistance + 1);
					else
						visIt->second = top.MovedDistance + 1;
				}
			}
		}

		if (prioQ.empty())
			return std::nullopt;
		else
			return prioQ.top().FirstStep;
	}

	// Check for potential target at the given location:
	UnitMap::iterator Battle::FindTarget(int x, int y, Unit::UnitType attackerType, UnitMap::iterator currentTarget)
	{
		auto target = m_units.find({ x, y });
		if (target != m_units.end() && target->second.GetUnitType() != attackerType)
		{
			// Update, if target has not been found yet or this target has lower hitpoints than the current target:
			if (currentTarget == m_units.end() || target->second.GetHitPoints() < currentTarget->second.GetHitPoints())
				return target;
			else
				return currentTarget;
		}
		else
			return currentTarget;
	};

	// Checks, if there are potential targets directly adjacent to this unit
	// If there are multiple, target the one with the lowest health (in reading order)
	UnitMap::iterator Battle::GetAdjacentTarget(int x, int y, Unit::UnitType attackerType)
	{
		auto target = m_units.end();
		
		// Check all 4 adjacent tiles (in reading order):
		target = FindTarget(x, y - 1, attackerType, target); // Top
		target = FindTarget(x - 1, y, attackerType, target); // Left
		target = FindTarget(x + 1, y, attackerType, target); // Right
		target = FindTarget(x, y + 1, attackerType, target); // Bottom
		return target;
	}

	std::vector<std::pair<int, int>> Battle::GetAdjacentCoords(int x, int y)
	{
		std::vector<std::pair<int, int>> coords;
		coords.reserve(4);

		// No bounds checking needed because the whole area is surrounded by walls
		// Check if the coordinate is neither occupied by a unit nor a wall:
		if (m_units.find({ x, y - 1 }) == m_units.end() && m_map[y - 1][x] != '#') coords.emplace_back(x, y - 1); // Top
		if (m_units.find({ x - 1, y }) == m_units.end() && m_map[y][x - 1] != '#') coords.emplace_back(x - 1, y); // Left
		if (m_units.find({ x + 1, y }) == m_units.end() && m_map[y][x + 1] != '#') coords.emplace_back(x + 1, y); // Right
		if (m_units.find({ x, y + 1 }) == m_units.end() && m_map[y + 1][x] != '#') coords.emplace_back(x, y + 1); // Bottom

		return coords;
	}

	Battle::BattleResult Battle::ExecuteCombat()
	{
		// True, if a unit moved or died (i.e. previously blocked units may be able to move again)
		bool hasBattleFieldChanged = false;

		// Count number of completed rounds during battle:
		int battleRounds = 0;
		while (IsBattleContinued())
		{
			// Update unit move states and revert change state of the battlefield afterwards:
			UpdateUnitMoveStates(hasBattleFieldChanged);
			hasBattleFieldChanged = false;

			// For every turn: each unit moves and / or attacks
			// -> Remove and re-insert units with their updated position, therefore iterator is updated manually
			// -> Updating is necessary, because it may influence units taking their turn later
			// -> Units must not be updated twice during a turn!
			auto unitIt = m_units.begin();
			while (unitIt != m_units.end())
			{
				const Unit& unit = unitIt->second;

				// Unit can only move once per turn:
				if (!CanUnitMoveThisTurn(unitIt->first.first, unitIt->first.second, hasBattleFieldChanged))
				{
					++unitIt;
					continue;
				}

				// Check if a target of the enemy team is available:
				// -> Combat only ends when a unit finds no targets during its turn
				if (!IsEnemyTargetAvailable(unit.GetUnitType()))
					break;

				int x = unitIt->first.first;
				int y = unitIt->first.second;

				auto target = GetAdjacentTarget(x, y, unit.GetUnitType());
				if (target != m_units.end())
				{
					// If target has been killed, mark battlefield as changed
					if (ExecuteAttack(unit, target))
						hasBattleFieldChanged = true;

					// End turn and continue with next unit:
					++unitIt;
				}
				else
				{
					// Find closest target to move to:
					auto nextMove = GetNextMove(x, y, unit.GetUnitType());
					if (!nextMove)
					{
						// No target could be reached, end turn:
						m_unitMoveStates[unitIt->first] = UnitMoveState::CouldNotMove;
						++unitIt;
						continue;
					}
					else
					{
						hasBattleFieldChanged = true;

						// Check if there is a target in range after move and if so, attack it:
						target = GetAdjacentTarget(nextMove.value().first, nextMove.value().second, unit.GetUnitType());
						if (target != m_units.end())
							ExecuteAttack(unit, target);

						// Update position: current unitIt / unit variables are invalid after this!

						// Insert unit with new position ...
						m_units.emplace(nextMove.value(), unit);
						m_unitMoveStates[nextMove.value()] = UnitMoveState::Moved; // remember this unit has moved already

						// ... and erase old position (returns iterator to next unit):
						m_unitMoveStates.erase(unitIt->first);
						unitIt = m_units.erase(unitIt);
					}
				}
			}

			// Only increase round counter, if all units have taken their turn
			// (meaning, the round has been completed)
			if (unitIt == m_units.end())
				++battleRounds;
		}

		BattleResult result;
		result.CompletedRounds = battleRounds;
		result.NumberOfElvesAlive = m_unitCounts[Unit::UnitType::Elf];
		result.NumberOfGoblinsAlive = m_unitCounts[Unit::UnitType::Goblin];
		result.TotalHitpointsOfRemainingUnits = std::accumulate(m_units.begin(), m_units.end(), 0,
			[](int sum, const UnitMap::value_type& x) { return sum + x.second.GetHitPoints(); }
		);

		return result;
	}

	int Battle::GetUnitCount(Unit::UnitType type)
	{
		return m_unitCounts.at(type);
	}

	void Battle::IncreaseElvesAttackPower(int increment)
	{
		for (auto& unitEntry : m_units)
		{
			Unit& unit = unitEntry.second;
			if (unit.GetUnitType() == Unit::UnitType::Elf)
				unit.IncreaseAttackPower(increment);
		}
	}
}
