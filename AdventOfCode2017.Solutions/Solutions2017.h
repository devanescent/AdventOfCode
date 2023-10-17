#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_InverseCaptcha.h"
#include "Day02\Day02_CorruptionChecksum.h"
#include "Day03\Day03_SpiralMemory.h"
#include "Day04\Day04_HighEntropyPassphrases.h"

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
				case 03:	return std::make_unique<Day03::SpiralMemory>();
				case 04:	return std::make_unique<Day04::HighEntropyPassphrases>();
				default:	return nullptr;
			}
		}
	};
}

