#include "Day15_BeverageBandits.h"
#include "Battle.h"

namespace AdventOfCode::Year2018::Day15
{
	BeverageBandits::BeverageBandits() : Day(15, "Beverage Bandits") {}

	uint64_t BeverageBandits::ExecutePart1(std::vector<std::string> map)
	{
		Battle battle(map);
		Battle::BattleResult result = battle.ExecuteCombat();

		return static_cast<uint64_t>(result.GetOutcome());
	}

	uint64_t BeverageBandits::ExecutePart2(std::vector<std::string> map)
	{
		// Find lowest increment to attack power so that no elf will die during combat:
		int increment = 50;

		int lastSuccess = 50;
		int lastLoss = 0;

		Battle::BattleResult lastSuccessfulResult;
		while (lastSuccess - lastLoss > 1)
		{
			Battle battle(map);
			battle.IncreaseElvesAttackPower(increment);
			int initialNumberOfElves = battle.GetUnitCount(Unit::UnitType::Elf);

			Battle::BattleResult result = battle.ExecuteCombat();

			if (result.NumberOfElvesAlive < initialNumberOfElves)
			{
				lastLoss = increment;
			}
			else
			{
				lastSuccess = increment;
				lastSuccessfulResult = result;
			}

			increment = lastLoss + (lastSuccess - lastLoss) / 2;
		}

		return static_cast<uint64_t>(lastSuccessfulResult.GetOutcome());
	}
}