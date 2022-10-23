#pragma once
#include "InputProcessor.h"
#include "Food.h"

namespace AdventOfCode::Year2020::Day21
{
	class FoodProcessor : public InputProcessorBase<Food>
	{
	public:
		std::vector<Food> Process(std::vector<std::string> input) override;
	};

}
