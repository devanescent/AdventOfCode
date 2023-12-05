#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_Trebuchet.h"
#include "Day02\Day02_CubeConundrum.h"
#include "Day03\Day03_GearRatios.h"
#include "Day04\Day04_Scratchcards.h"
#include "Day05\Day05_IfYouGiveASeedAFertilizer.h"

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
				default:	return nullptr;
			}
		}
	};
}

