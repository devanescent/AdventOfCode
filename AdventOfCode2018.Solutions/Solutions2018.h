#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_ChronalCalibration.h"
#include "Day02\Day02_InventoryManagementSystem.h"
#include "Day03\Day03_NoMatterHowYouSliceIt.h"
#include "Day04\Day04_ReposeRecord.h"
#include "Day05\Day05_AlchemicalReduction.h"
#include "Day06\Day06_ChronalCoordinates.h"
#include "Day07\Day07_TheSumOfItsParts.h"
#include "Day08\Day08_MemoryManeuver.h"
#include "Day09\Day09_MarbleMania.h"
#include "Day10\Day10_TheStarsAlign.h"
#include "Day11\Day11_ChronalCharge.h"
#include "Day12\Day12_SubterraneanSustainability.h"
#include "Day13\Day13_MineCartMadness.h"
#include "Day14\Day14_ChocolateCharts.h"
#include "Day15\Day15_BeverageBandits.h"
#include "Day16\Day16_ChronalClassification.h"
#include "Day17\Day17_ReservoirResearch.h"
#include "Day18\Day18_SettlersOfTheNorthPole.h"
#include "Day19\Day19_GoWithTheFlow.h"
// TODO: Day 20
#include "Day21\Day21_ChronalConversion.h"
#include "Day22\Day22_ModeMaze.h"
#include "Day23\Day23_ExperimentalEmergencyTeleportation.h"
#include "Day24\Day24_ImmuneSystemSimulator20XX.h"
#include "Day25\Day25_FourDimensionalAdventure.h"

namespace AdventOfCode::Year2018
{
	class Solutions2018 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::ChronalCalibration>();
				case  2:	return std::make_unique<Day02::InventoryManagementSystem>();
				case  3:	return std::make_unique<Day03::NoMatterHowYouSliceIt>();
				case  4:	return std::make_unique<Day04::ReposeRecord>();
				case  5:	return std::make_unique<Day05::AlchemicalReduction>();
				case  6:	return std::make_unique<Day06::ChronalCoordinates>();
				// case  7:	return std::make_unique<Day07::TheSumOfItsParts>(); // TODO: parameterless ctor?
				case  8:	return std::make_unique<Day08::MemoryManeuver>();
				case  9:	return std::make_unique<Day09::MarbleMania>();
				case 10:	return std::make_unique<Day10::TheStarsAlign>();
				case 11:	return std::make_unique<Day11::ChronalCharge>();
				case 12:	return std::make_unique<Day12::SubterraneanSustainability>();
				case 13:	return std::make_unique<Day13::MineCartMadness>();
				case 14:	return std::make_unique<Day14::ChocolateCharts>();
				case 15:	return std::make_unique<Day15::BeverageBandits>();
				case 16:	return std::make_unique<Day16::ChronalClassification>();
				case 17:	return std::make_unique<Day17::ReservoirResearch>();
				case 18:	return std::make_unique<Day18::SettlersOfTheNorthPole>();
				case 19:	return std::make_unique<Day19::GoWithTheFlow>();
				//case 20:
				case 21:	return std::make_unique<Day21::ChronalConversion>();
				case 22:	return std::make_unique<Day22::ModeMaze>();
				case 23:	return std::make_unique<Day23::ExperimentalEmergencyTeleportation>();
				case 24:	return std::make_unique<Day24::ImmuneSystemSimulator20XX>();
				case 25:	return std::make_unique<Day25::FourDimensionalAdventure>();
				default:	return nullptr;
			}
		}
	};
}

