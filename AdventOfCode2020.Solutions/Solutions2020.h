#pragma once
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
// TODO: Day 19
#include "Day20\Day20_JurassicJigsaw.h"
// TODO: Day 21
#include "Day22\Day22_CrabCombat.h"
#include "Day23\Day23_CrabCups.h"
#include "Day24\Day24_LobbyLayout.h"
#include "Day25\Day25_ComboBreaker.h"
#include <memory>

namespace AdventOfCode::Year2020
{
	class Solutions
	{
	public:
		Solutions();

	//private:
		std::vector<std::unique_ptr<Day>> m_days;
	};
}

