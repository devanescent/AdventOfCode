#pragma once
#include <set>
#include <string>

namespace AdventOfCode::Year2020::Day21
{
	class Food
	{
	public:
		std::set<std::string> Ingredients;
		std::set<std::string> Allergens;
	};
}
