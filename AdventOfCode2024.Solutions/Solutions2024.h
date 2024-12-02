#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01/Day01_HistorianHysteria.h"
#include "Day02/Day02_RedNosedReports.h"

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
				default:	return nullptr;
			}
		}
	};
}

