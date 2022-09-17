#include "Day24_ImmuneSystemSimulator20XX.h"

namespace AdventOfCode::Year2018::Day24
{
	ImmuneSystemSimulator20XX::ImmuneSystemSimulator20XX() : DayT(24, "Immune System Simulator 20XX") {}

	ImmuneSystemSimulator20XX::FightResult ImmuneSystemSimulator20XX::SimulateFights(Army& immuneSystem, Army& infection)
	{
		while (true)
		{
			// Target selection phase: Get fights from each army:
			auto immuneSystem_fights = immuneSystem.GetFights(infection);
			auto infection_fights = infection.GetFights(immuneSystem);

			// Attacking phase: Combine fights and sort by initiative:
			std::vector<Fight> fights;
			fights.insert(fights.end(), immuneSystem_fights.begin(), immuneSystem_fights.end());
			fights.insert(fights.end(), infection_fights.begin(), infection_fights.end());

			std::sort(fights.begin(), fights.end(),
				[](const Fight& f1, const Fight& f2)
				{
					// Higher initiative attacks first:
					return f1.GetAttackerInitiative() > f2.GetAttackerInitiative();
				}
			);

			// Execute all fights in order:
			unsigned int unitsDied = 0;
			for (Fight& f : fights)
				unitsDied += f.ExecuteFight();

			// If no units died during the fight, it's a draw:
			if (!unitsDied)
				return FightResult::Draw;

			// If one army does not contain any units anymore, the fight ends:
			else if (!immuneSystem.ContainsAliveUnits())
				return FightResult::InfectionWon;

			else if (!infection.ContainsAliveUnits())
				return FightResult::ImmuneSystemWon;
		}
	}


	uint64_t ImmuneSystemSimulator20XX::ExecutePart1(std::vector<Army> armies)
	{
		Army& immuneSystem = armies[0];
		Army& infection = armies[1];

		uint64_t winningArmyUnits = 0;

		FightResult result = SimulateFights(immuneSystem, infection);
		if (result == FightResult::ImmuneSystemWon)
			winningArmyUnits = immuneSystem.GetNumberOfAliveUnits();
		else if (result == FightResult::InfectionWon)
			winningArmyUnits = infection.GetNumberOfAliveUnits();

		return winningArmyUnits;
	}


	uint64_t ImmuneSystemSimulator20XX::ExecutePart2(std::vector<Army> armies)
	{
		Army& immuneSystem = armies[0];
		Army& infection = armies[1];

		uint64_t winningArmyUnits = 0;

		unsigned int lastWinningBoost = 20000; // hopefully high enough to make the immune system win...
		unsigned int lastLoosingBoost = 0;

		while (lastWinningBoost > lastLoosingBoost + 1)
		{
			// Revive all units of both armies:
			immuneSystem.ResetArmy();
			infection.ResetArmy();

			// Currently applied boost:
			int currentBoost = lastLoosingBoost + (lastWinningBoost - lastLoosingBoost) / 2;
			immuneSystem.ApplyAttackBoost(currentBoost);
			
			// Run the fight:
			auto result = SimulateFights(immuneSystem, infection);
			if (result == FightResult::ImmuneSystemWon)
			{
				lastWinningBoost = currentBoost;
				winningArmyUnits = immuneSystem.GetNumberOfAliveUnits();
			}
			else
			{
				lastLoosingBoost = currentBoost;
			}
		}

		return winningArmyUnits;
	}
}