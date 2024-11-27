#include "IntProcessor.h"
#include "CharDigitConverter.h"
#include <algorithm>
#include <ranges>
#include <sstream>
#include <string_view>

namespace AdventOfCode
{
	// IntProcessingMode::ValuesAsDigits
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsDigits>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::ranges::transform(input[0].begin(), input[0].end(), std::back_inserter(intList), CharToDigit<int>);
		}

		return intList;
	}

	// IntProcessingMode::ValuePerLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuePerLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;
		intList.reserve(input.size());

		std::ranges::transform(input, std::back_inserter(intList), [](const std::string& s) { return std::stoi(s); });

		return intList;
	}

	// IntProcessingMode::ValuesAsCommaSeparatedLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::istringstream iss(input[0]);
			std::string valStr;

			while (std::getline(iss, valStr, ','))
				intList.push_back(std::stoi(valStr));
		}

		return intList;
	}

	// IntProcessingMode::ValuesAsSpaceSeparatedLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::istringstream iss(input[0]);
			std::string valStr;

			while (iss >> valStr)
				intList.push_back(std::stoi(valStr));
		}

		return intList;
	}

	// IntArrayProcessor: converts input to 2D array structure
	std::vector<std::vector<int>> IntArrayProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::vector<int>> result;
		result.reserve(input.size());

		std::ranges::transform(input, std::back_inserter(result),
			[](std::string_view line)
			{
				std::vector<int> ints;
				ints.reserve(line.size());
				std::ranges::transform(line, std::back_inserter(ints), CharToDigit<int>);
				return ints;
			}
		);

		return result;
	}

	std::vector<uint64_t> LargeIntProcessor::Process(std::vector<std::string> input)
	{
		std::vector<uint64_t> lIntList;
		lIntList.reserve(input.size());

		std::ranges::transform(input, std::back_inserter(lIntList), [](const std::string& s) { return std::stoull(s); });

		return lIntList;
	}
}