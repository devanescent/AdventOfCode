#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <optional>

namespace AdventOfCode
{
	using IteratorPair = std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>;

	std::optional<IteratorPair> FindPairForGivenSum(const std::vector<int>& nums, int sum);

	template <typename T>
	std::vector<T> SplitLine(const std::string& line, char delimiter, T(*Conv)(const std::string&), bool(*Pred)(const std::string&) = nullptr)
	{
		std::vector<T> result;

		std::istringstream inStream = std::istringstream(line);
		std::string currentValue;

		while (std::getline(inStream, currentValue, delimiter))
		{
			if (Pred && !Pred(currentValue))
				continue;
			else
				result.push_back(Conv(currentValue));
		}

		return result;
	}
}