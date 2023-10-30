#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_SonarSweep.h"
#include "Day02\Day02_Dive.h"
#include "Day03\Day03_BinaryDiagnostic.h"
#include "Day04\Day04_GiantSquid.h"
#include "Day05\Day05_HydrothermalVenture.h"
#include "Day06\Day06_Lanternfish.h"
#include "Day07\Day07_TheTreacheryOfWhales.h"
#include "Day08\Day08_SevenSegmentSearch.h"
#include "Day09\Day09_SmokeBasin.h"
#include "Day10\Day10_SyntaxScoring.h"
#include "Day11\Day11_DumboOctopus.h"
#include "Day12\Day12_PassagePathing.h"
#include "Day13\Day13_TransparentOrigami.h"
#include "Day14\Day14_ExtendedPolymerization.h"
#include "Day15\Day15_Chiton.h"
#include "Day16\Day16_PacketDecoder.h"
#include "Day17\Day17_TrickShot.h"
#include "Day18\Day18_Snailfish.h"
// TODO: Day 19
#include "Day20\Day20_TrenchMap.h"
#include "Day21\Day21_DiracDice.h"
#include "Day22\Day22_ReactorReboot.h"
// TODO: Day 23
// TODO: Day 24
#include "Day25\Day25_SeaCucumber.h"

namespace AdventOfCode::Year2021
{
	class Solutions2021 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::SonarSweep>();
				case  2:	return std::make_unique<Day02::Dive>();
				case  3:	return std::make_unique<Day03::BinaryDiagnostic>();
				case  4:	return std::make_unique<Day04::GiantSquid>();
				case  5:	return std::make_unique<Day05::HydrothermalVenture>();
				case  6:	return std::make_unique<Day06::Lanternfish>();
				case  7:	return std::make_unique<Day07::TheTreacheryOfWhales>();
				case  8:	return std::make_unique<Day08::SevenSegmentSearch>();
				case  9:	return std::make_unique<Day09::SmokeBasin>();
				case 10:	return std::make_unique<Day10::SyntaxScoring>();
				case 11:	return std::make_unique<Day11::DumboOctopus>();
				case 12:	return std::make_unique<Day12::PassagePathing>();
				case 13:	return std::make_unique<Day13::TransparentOrigami>();
				case 14:	return std::make_unique<Day14::ExtendedPolymerization>();
				case 15:	return std::make_unique<Day15::Chiton>();
				case 16:	return std::make_unique<Day16::PacketDecoder>();
				case 17:	return std::make_unique<Day17::TrickShot>();
				case 18:	return std::make_unique<Day18::Snailfish>();
				// case 19
				case 20:	return std::make_unique<Day20::TrenchMap>();
				case 21:	return std::make_unique<Day21::DiracDice>();
				case 22:	return std::make_unique<Day22::ReactorReboot>();
				// case 23
				// case 24
				case 25:	return std::make_unique<Day25::SeaCucumber>();
				default:	return nullptr;
			}
		}
	};
}

