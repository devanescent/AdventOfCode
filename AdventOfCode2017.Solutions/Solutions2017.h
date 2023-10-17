#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_InverseCaptcha.h"
#include "Day02\Day02_CorruptionChecksum.h"

namespace AdventOfCode::Year2017
{
	class Solutions2017 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				case 01:	return std::make_unique<Day01::InverseCaptcha>();
				case 02:	return std::make_unique<Day02::CorruptionChecksum>();
				default:	return nullptr;
			}
		}
	};
}

