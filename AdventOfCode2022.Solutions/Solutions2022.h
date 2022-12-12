#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_CalorieCounting.h"
#include "Day02\Day02_RockPaperScissors.h"
#include "Day03\Day03_RucksackReorganization.h"
#include "Day04\Day04_CampCleanup.h"
#include "Day05\Day05_SupplyStacks.h"
#include "Day06\Day06_TuningTrouble.h"
#include "Day07\Day07_NoSpaceLeftOnDevice.h"
#include "Day08\Day08_TreetopTreeHouse.h"
#include "Day09\Day09_RopeBridge.h"
#include "Day10\Day10_CathodeRayTube.h"
#include "Day11\Day11_MonkeyInTheMiddle.h"
#include "Day12\Day12_HillClimbingAlgorithm.h"

namespace AdventOfCode::Year2022
{
	class Solutions2022 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				case 1:		return std::make_unique<Day01::CalorieCounting>();
				case 2:		return std::make_unique<Day02::RockPaperScissors>();
				case 3:		return std::make_unique<Day03::RucksackReorganization>();
				case 4:		return std::make_unique<Day04::CampCleanup>();
				case 5:		return std::make_unique<Day05::SupplyStacks>();
				case 6:		return std::make_unique<Day06::TuningTrouble>();
				case 7:		return std::make_unique<Day07::NoSpaceLeftOnDevice>();
				case 8:		return std::make_unique<Day08::TreetopTreeHouse>();
				case 9:		return std::make_unique<Day09::RopeBridge>();
				case 10:	return std::make_unique<Day10::CathodeRayTube>();
				case 11:	return std::make_unique<Day11::MonkeyInTheMiddle>();
				case 12:	return std::make_unique<Day12::HillClimbingAlgorithm>();
				default:	return nullptr;
			}
		}
	};
}

