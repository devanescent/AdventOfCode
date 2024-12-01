#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01/Day01_HistorianHysteria.h"

namespace AdventOfCode::Year2024
{
	class Solutions2024 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::HistorianHysteria>();
				default:	return nullptr;
			}
		}
	};
}

