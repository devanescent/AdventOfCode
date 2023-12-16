#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_Trebuchet.h"
#include "Day02\Day02_CubeConundrum.h"
#include "Day03\Day03_GearRatios.h"
#include "Day04\Day04_Scratchcards.h"
#include "Day05\Day05_IfYouGiveASeedAFertilizer.h"
#include "Day06\Day06_WaitForIt.h"
#include "Day07\Day07_CamelCards.h"
#include "Day08\Day08_HauntedWasteland.h"
#include "Day09\Day09_MirageMaintenance.h"
#include "Day10\Day10_PipeMaze.h"
#include "Day11\Day11_CosmicExpansion.h"
#include "Day12\Day12_HotSprings.h"
#include "Day13\Day13_PointOfIncidence.h"
#include "Day14\Day14_ParabolicReflectorDish.h"
#include "Day15\Day15_LensLibrary.h"
#include "Day16\Day16_TheFloorWillBeLava.h"

namespace AdventOfCode::Year2023
{
	class Solutions2023 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::Trebuchet>();
				case  2:	return std::make_unique<Day02::CubeConundrum>();
				case  3:	return std::make_unique<Day03::GearRatios>();
				case  4:	return std::make_unique<Day04::Scratchcards>();
				case  5:	return std::make_unique<Day05::IfYouGiveASeedAFertilizer>();
				case  6:	return std::make_unique<Day06::WaitForIt>();
				case  7:	return std::make_unique<Day07::CamelCards>();
				case  8:	return std::make_unique<Day08::HauntedWasteland>();
				case  9:	return std::make_unique<Day09::MirageMaintenance>();
				case 10:	return std::make_unique<Day10::PipeMaze>();
				case 11:	return std::make_unique<Day11::CosmicExpansion>();
				case 12:	return std::make_unique<Day12::HotSprings>();
				case 13:	return std::make_unique<Day13::PointOfIncidence>();
				case 14:	return std::make_unique<Day14::ParabolicReflectorDish>();
				case 15:	return std::make_unique<Day15::LensLibrary>();
				case 16:	return std::make_unique<Day16::TheFloorWillBeLava>();
				default:	return nullptr;
			}
		}
	};
}

