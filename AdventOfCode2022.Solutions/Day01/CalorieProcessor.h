#pragma once
#include "InputProcessor.h"
#include "CarriedCalories.h"

namespace AdventOfCode::Year2022::Day01
{
	class CalorieProcessor : public InputProcessorBase<CarriedCalories>
	{
	public:
		std::vector<CarriedCalories> Process(std::vector<std::string> input) override;
	};
}
