#pragma once
#include "DayT.h"
#include "FoodProcessor.h"
#include <map>

namespace AdventOfCode::Year2020::Day21
{
	class AllergenAssessment : public DayT<FoodProcessor>
	{
	public:
		AllergenAssessment();

	protected:
		uint64_t ExecutePart1(std::vector<Food> foods) override;
		uint64_t ExecutePart2(std::vector<Food> foods) override;

	private:
		// Maps each allergen to a set of potential ingredients:
		std::map<std::string, std::set<std::string>> MapIngredientsToAllergens(const std::vector<Food>& foods);
	};
}


