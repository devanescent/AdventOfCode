#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01/Day01_HistorianHysteria.h"
#include "Day02/Day02_RedNosedReports.h"
#include "Day03/Day03_MullItOver.h"
#include "Day04/Day04_CeresSearch.h"
#include "Day05/Day05_PrintQueue.h"
#include "Day06/Day06_GuardGallivant.h"
#include "Day07/Day07_BridgeRepair.h"
#include "Day08/Day08_ResonantCollinearity.h"
#include "Day09/Day09_DiskFragmenter.h"

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
				case  7:	return std::make_unique<Day07::BridgeRepair>();
				case  8:	return std::make_unique<Day08::ResonantCollinearity>();
				case  9:	return std::make_unique<Day09::DiskFragmenter>();
				default:	return nullptr;
			}
		}
	};
}

