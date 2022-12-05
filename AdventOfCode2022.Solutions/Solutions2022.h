#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_CalorieCounting.h"
#include "Day02\Day02_RockPaperScissors.h"
#include "Day03\Day03_RucksackReorganization.h"
#include "Day04\Day04_CampCleanup.h"

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
				default:	return nullptr;
			}
		}
	};
}

