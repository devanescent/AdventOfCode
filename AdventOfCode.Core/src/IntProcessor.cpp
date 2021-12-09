#include "IntProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode
{
	// IntProcessingMode::ValuesAsDigits
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsDigits>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::transform(input[0].begin(), input[0].end(), std::back_inserter(intList), [](char c) { return c - '0'; });
		}

		return intList;
	}

	// IntProcessingMode::ValuePerLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuePerLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;
		intList.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(intList), [](const std::string s) { return std::stoi(s); });

		return intList;
	}

	// IntProcessingMode::ValuesAsSingleLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsSingleLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::istringstream iss = std::istringstream(input[0]);
			std::string valStr;

			while (std::getline(iss, valStr, ','))
				intList.push_back(std::stoi(valStr));
		}

		return intList;
	}
}