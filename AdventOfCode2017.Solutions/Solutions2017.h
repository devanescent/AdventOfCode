#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_InverseCaptcha.h"

namespace AdventOfCode::Year2017
{
	class Solutions2017 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				case 01:	return std::make_unique<Day01::InverseCaptcha>();
				default:	return nullptr;
			}
		}
	};
}

