#include "Day01_CalorieCounting.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2022::Day01
{
	CalorieCounting::CalorieCounting() : DayT(01, "Calorie Counting") { }

	uint64_t CalorieCounting::ExecutePart1(std::vector<CarriedCalories> calories)
	{
		// Get the total calories of the elf carrying the most calories:
		return std::max_element(calories.begin(), calories.end(),
			[](const CarriedCalories& c1, const CarriedCalories& c2) { return c1.GetTotalCalories() < c2.GetTotalCalories(); }
		)->GetTotalCalories();
	}

	uint64_t CalorieCounting::ExecutePart2(std::vector<CarriedCalories> calories)
	{
		// Get the total of calories carried by the top three elfs:
		std::partial_sort(calories.begin(), calories.begin() + 3, calories.end(),
			[](const CarriedCalories& c1, const CarriedCalories& c2) { return c1.GetTotalCalories() > c2.GetTotalCalories(); }
		);

		// Sum up:
		return std::accumulate(calories.begin(), calories.begin() + 3, 0ull, [](uint64_t total, const CarriedCalories& cal)
			{ return total + cal.GetTotalCalories(); }
		);
	}
}
