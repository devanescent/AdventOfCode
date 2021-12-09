#pragma once
#include <array>
#include <string>
#include <algorithm>
#include <functional>
#include <optional>

namespace AdventOfCode::Year2021::Day08
{
	class SignalPatternObservation
	{
	public:
		std::array<std::string, 10>	UniquePatterns;	// 10 observed patterns for digits
		std::array<std::string, 4>	DisplayedDigits;	// Digits that are actually displayed

		// Find a specific pattern based on a predicate:
		/*std::optional<const std::string&> FindPattern(std::function<bool(const std::string&)> pred) const
		{
			auto res = std::find_if(UniquePatterns.begin(), UniquePatterns.end(), pred);

			if (res != UniquePatterns.end())
				return *res;
			else
				return {};
		}*/
	};
}