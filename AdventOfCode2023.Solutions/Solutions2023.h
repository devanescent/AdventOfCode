#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_Trebuchet.h"
#include "Day02\Day02_CubeConundrum.h"
#include "Day03\Day03_GearRatios.h"

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
				default:	return nullptr;
			}
		}
	};
}

