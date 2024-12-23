#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01/Day01_HistorianHysteria.h"
#include "Day02/Day02_RedNosedReports.h"
#include "Day03/Day03_MullItOver.h"
#include "Day04/Day04_CeresSearch.h"
#include "Day05/Day05_PrintQueue.h"
#include "Day06/Day06_GuardGallivant.h"
#include "Day07/Day07_BridgeRepair.h"
#include "Day08/Day08_ResonantCollinearity.h"
#include "Day09/Day09_DiskFragmenter.h"
#include "Day10/Day10_HoofIt.h"
#include "Day11/Day11_PlutonianPebbles.h"
#include "Day12/Day12_GardenGroups.h"
#include "Day13/Day13_ClawContraption.h"
#include "Day14/Day14_RestroomRedoubt.h"
#include "Day15/Day15_WarehouseWoes.h"
#include "Day16/Day16_ReindeerMaze.h"
#include "Day17/Day17_ChronospatialComputer.h"
#include "Day18/Day18_RAMRun.h"
#include "Day19/Day19_LinenLayout.h"
#include "Day20/Day20_RaceCondition.h"
#include "Day21/Day21_KeypadConundrum.h"
#include "Day22/Day22_MonkeyMarket.h"
#include "Day23/Day23_LANParty.h"
#include "Day24/Day24_CrossedWires.h"

namespace AdventOfCode::Year2024
{
	class Solutions2024 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::HistorianHysteria>();
				case  2:	return std::make_unique<Day02::RedNosedReports>();
				case  3:	return std::make_unique<Day03::MullItOver>();
				case  4:	return std::make_unique<Day04::CeresSearch>();
				case  5:	return std::make_unique<Day05::PrintQueue>();
				case  6:	return std::make_unique<Day06::GuardGallivant>();
				case  7:	return std::make_unique<Day07::BridgeRepair>();
				case  8:	return std::make_unique<Day08::ResonantCollinearity>();
				case  9:	return std::make_unique<Day09::DiskFragmenter>();
				case 10:	return std::make_unique<Day10::HoofIt>();
				case 11:	return std::make_unique<Day11::PlutonianPebbles>();
				case 12:	return std::make_unique<Day12::GardenGroups>();
				case 13:	return std::make_unique<Day13::ClawContraption>();
				case 14:	return std::make_unique<Day14::RestroomRedoubt>();
				case 15:	return std::make_unique<Day15::WarehouseWoes>();
				case 16:	return std::make_unique<Day16::ReindeerMaze>();
				case 17:	return std::make_unique<Day17::ChronospatialComputer>();
				case 18:	return std::make_unique<Day18::RAMRun>();
				case 19:	return std::make_unique<Day19::LinenLayout>();
				case 20:	return std::make_unique<Day20::RaceCondition>();
				case 21:	return std::make_unique<Day21::KeypadConundrum>();
				case 22:	return std::make_unique<Day22::MonkeyMarket>();
				case 23:	return std::make_unique<Day23::LANParty>();
				case 24:	return std::make_unique<Day24::CrossedWires>();
				default:	return nullptr;
			}
		}
	};
}

