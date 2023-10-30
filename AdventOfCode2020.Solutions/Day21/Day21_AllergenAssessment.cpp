#include "Day21_AllergenAssessment.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day21
{
	AllergenAssessment::AllergenAssessment() : DayT(21, "Allergen Assessment") {}

	uint64_t AllergenAssessment::ExecutePart1(std::vector<Food> foods)
	{
		std::map<std::string, std::set<std::string>> ingredientsByAllergen = MapIngredientsToAllergens(foods);

		// Collect set of all ingredients that can potentially contain an allergen:
		std::set<std::string> ingredientsWithAllergens;
		for (const auto& allergen : ingredientsByAllergen)
		{
			ingredientsWithAllergens.insert(allergen.second.begin(), allergen.second.end());
		}

		// Last, count number of ingredients in foods, that cannot contain an allergen:
		uint64_t harmlessIngredients = 0;

		for (const Food& f : foods)
		{
			std::set<std::string> result;
			std::set_difference(
				f.Ingredients.begin(), f.Ingredients.end(),                       // Find ingredients from this set ...
				ingredientsWithAllergens.begin(), ingredientsWithAllergens.end(), // ... that are not contained in this set
				std::inserter(result, result.end())
			);
			harmlessIngredients += result.size();
		}

		return harmlessIngredients;
	}

	std::string AllergenAssessment::ExecutePart2(std::vector<Food> foods)
	{
		std::map<std::string, std::set<std::string>> ingredientsByAllergen = MapIngredientsToAllergens(foods);
		std::map<std::string, std::string> allergenResults; // which allergen is contained in which ingredient

		auto allergenWithSingleIngredient = ingredientsByAllergen.end();

		while ((allergenWithSingleIngredient = std::find_if(ingredientsByAllergen.begin(), ingredientsByAllergen.end(), 
			[](const auto& allergen) { return allergen.second.size() == 1; } ))
			!= ingredientsByAllergen.end())
		{
			const std::string& allergenName = allergenWithSingleIngredient->first;
			std::string ingredient = *allergenWithSingleIngredient->second.begin(); // copied, because this will be erased from the map
			allergenResults[allergenName] = ingredient;

			// Remove the single ingredient from all allergen sets:
			for (auto& entry : ingredientsByAllergen)
				entry.second.erase(ingredient);
		}

		// Combine to string in alphabetical order of allergens (correct order is already enforced by the map)
		std::string canonicalDangerousIngredientList;
		for (const auto& resultEntry : allergenResults)
		{
			if (!canonicalDangerousIngredientList.empty())
				canonicalDangerousIngredientList.append(",");

			canonicalDangerousIngredientList.append(resultEntry.second);
		}

		return canonicalDangerousIngredientList;
	}

	std::map<std::string, std::set<std::string>> AllergenAssessment::MapIngredientsToAllergens(const std::vector<Food>& foods)
	{
		std::map<std::string, std::set<std::string>> ingredientsByAllergen;

		for (const Food& f : foods)
		{
			for (const std::string& allergen : f.Allergens)
			{
				auto a = ingredientsByAllergen.find(allergen);
				if (a == ingredientsByAllergen.end())
				{
					// First occurance of this allergen: set ingredients
					ingredientsByAllergen[allergen] = f.Ingredients;
				}
				else
				{
					// Intersect ingredients with existing set:
					// -> for an allergen to be contained in an ingredient, it has to be present 
					//    in all foods that possibly contain this allergen
					std::set<std::string> resultIngredients;
					std::set_intersection(
						f.Ingredients.begin(), f.Ingredients.end(),
						a->second.begin(), a->second.end(),
						std::inserter(resultIngredients, resultIngredients.end())
					);

					a->second = resultIngredients;
				}
			}
		}

		return ingredientsByAllergen;
	}
}