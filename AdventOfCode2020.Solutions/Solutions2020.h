#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_ReportRepair.h"
#include "Day02\Day02_PasswordPhilosophy.h"
#include "Day03\Day03_TobogganTrajectory.h"
#include "Day04\Day04_PassportProcessing.h"
#include "Day05\Day05_BinaryBoarding.h"
#include "Day06\Day06_CustomCustoms.h"
#include "Day07\Day07_HandyHaversacks.h"
#include "Day08\Day08_HandheldHalting.h"
#include "Day09\Day09_EncodingError.h"
#include "Day10\Day10_AdapterArray.h"
#include "Day11\Day11_SeatingSystem.h"
#include "Day12\Day12_RainRisk.h"
#include "Day13\Day13_ShuttleSearch.h"
#include "Day14\Day14_DockingData.h"
#include "Day15\Day15_RambunctiousRecitation.h"
#include "Day16\Day16_TicketTranslation.h"
#include "Day17\Day17_ConvayCubes.h"
#include "Day18\Day18_OperationOrder.h"
#include "Day19\Day19_MonsterMessages.h"
#include "Day20\Day20_JurassicJigsaw.h"
#include "Day21\Day21_AllergenAssessment.h"
#include "Day22\Day22_CrabCombat.h"
#include "Day23\Day23_CrabCups.h"
#include "Day24\Day24_LobbyLayout.h"
#include "Day25\Day25_ComboBreaker.h"

namespace AdventOfCode::Year2020
{
	class Solutions2020 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::ReportRepair>();
				case  2:	return std::make_unique<Day02::PasswordPhilosophy>();
				case  3:	return std::make_unique<Day03::TobogganTrajectory>();
				case  4:	return std::make_unique<Day04::PassportProcessing>();
				case  5:	return std::make_unique<Day05::BinaryBoarding>();
				case  6:	return std::make_unique<Day06::CustomCustoms>();
				case  7:	return std::make_unique<Day07::HandyHaversacks>();
				case  8:	return std::make_unique<Day08::HandheldHalting>();
				case  9:	return std::make_unique<Day09::EncodingError>();
				case 10:	return std::make_unique<Day10::AdapterArray>();
				case 11:	return std::make_unique<Day11::SeatingSystem>();
				case 12:	return std::make_unique<Day12::RainRisk>();
				case 13:	return std::make_unique<Day13::ShuttleSearch>();
				case 14:	return std::make_unique<Day14::DockingData>();
				// case 15:	return std::make_unique<Day15::RambunctiousRecitation>(); // TODO: parameterless ctor?
				case 16:	return std::make_unique<Day16::TicketTranslation>();
				case 17:	return std::make_unique<Day17::ConvayCubes>();
				case 18:	return std::make_unique<Day18::OperationOrder>();
				case 19:	return std::make_unique<Day19::MonsterMessages>();
				case 20:	return std::make_unique<Day20::JurassicJigsaw>();
				case 21:	return std::make_unique<Day21::AllergenAssessment>();
				case 22:	return std::make_unique<Day22::CrabCombat>();
				case 23:	return std::make_unique<Day23::CrabCups>();
				case 24:	return std::make_unique<Day24::LobbyLayout>();
				case 25:	return std::make_unique<Day25::ComboBreaker>();
				default:	return nullptr;
			}
		}
	};
}

