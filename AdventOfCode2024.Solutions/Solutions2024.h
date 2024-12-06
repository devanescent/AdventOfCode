#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01/Day01_HistorianHysteria.h"
#include "Day02/Day02_RedNosedReports.h"
#include "Day03/Day03_MullItOver.h"
#include "Day04/Day04_CeresSearch.h"
#include "Day05/Day05_PrintQueue.h"
#include "Day06/Day06_GuardGallivant.h"

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
				default:	return nullptr;
			}
		}
	};
}

