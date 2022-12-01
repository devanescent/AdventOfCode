#pragma once
#include "DayT.h"
#include "CalorieProcessor.h"

namespace AdventOfCode::Year2022::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: Calorie Counting
	// ---------------------------------------------------------------------------
	class CalorieCounting : public DayT<CalorieProcessor>
	{
	public:
		CalorieCounting();

	protected:
		uint64_t ExecutePart1(std::vector<CarriedCalories> calories) override;
		uint64_t ExecutePart2(std::vector<CarriedCalories> calories) override;
	};
}
