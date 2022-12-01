#include "CalorieProcessor.h"

namespace AdventOfCode::Year2022::Day01
{
	std::vector<CarriedCalories> CalorieProcessor::Process(std::vector<std::string> input)
	{
		std::vector<CarriedCalories> allCalories;
		CarriedCalories calories;

		for (const std::string& line : input)
		{
			if (!line.empty())
				calories.AddCalories(atoi(line.c_str()));
			else
			{
				allCalories.emplace_back(calories);
				calories = CarriedCalories();
			}
		}

		allCalories.emplace_back(calories);
		return allCalories;
	}
}
