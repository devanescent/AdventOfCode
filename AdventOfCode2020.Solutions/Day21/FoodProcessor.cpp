#pragma once
#include "FoodProcessor.h"
#include <regex>

namespace AdventOfCode::Year2020::Day21
{
	std::vector<Food> FoodProcessor::Process(std::vector<std::string> input)
	{
		std::regex ingredientPattern = std::regex("(?: |^)([a-z]+) ");
		// -> word followed by a space and preceeded by either a space or the start of the line
		//    in order to not match the 'contains' inside the allergen list

		std::regex allergenPattern = std::regex("([a-z]+)(?:\\,|\\))");
		// -> word followed by either a comma or a closing parenthesis

		std::smatch matches;

		std::vector<Food> foods;
		foods.reserve(input.size());
		for (std::string& line : input)
		{
			Food f;

			while (std::regex_search(line, matches, ingredientPattern))
			{
				f.Ingredients.emplace(matches[1]); // group without the matching space at the end
				line = matches.suffix();
			}
			while (std::regex_search(line, matches, allergenPattern))
			{
				f.Allergens.emplace(matches[1]); // group without the matching ',' or ')' at the end
				line = matches.suffix();
			}

			foods.emplace_back(f);
		}

		return foods;
	}
}

