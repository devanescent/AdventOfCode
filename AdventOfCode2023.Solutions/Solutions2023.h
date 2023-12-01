#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_Trebuchet.h"

namespace AdventOfCode::Year2023
{
	class Solutions2023 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::Trebuchet>();
				default:	return nullptr;
			}
		}
	};
}

