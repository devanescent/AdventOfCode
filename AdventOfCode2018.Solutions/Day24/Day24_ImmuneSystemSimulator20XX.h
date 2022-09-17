#pragma once
#include "DayT.h"
#include "ArmyProcessor.h"

namespace AdventOfCode::Year2018::Day24
{
	// ---------------------------------------------------------------------------
	// Day23: Experimental Emergency Teleportation
	// ---------------------------------------------------------------------------
	class ImmuneSystemSimulator20XX : public DayT<ArmyProcessor>
	{
	public:
		ImmuneSystemSimulator20XX();

		uint64_t ExecutePart1(std::vector<Army> armies) override;
		uint64_t ExecutePart2(std::vector<Army> nanobots) override;

	private:
		enum class FightResult
		{
			ImmuneSystemWon,
			InfectionWon,
			Draw
		};

		FightResult SimulateFights(Army& immuneSystem, Army& infection);

	};
}