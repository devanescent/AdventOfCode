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

		std::transform(input.begin(), input.end(), std::back_inserter(intList), [](const std::string& s) { return std::stoi(s); });

		return intList;
	}

	// IntProcessingMode::ValuesAsCommaSeparatedLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>::Process(const std::vector<std::string> input)
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

	// IntProcessingMode::ValuesAsSpaceSeparatedLine
	std::vector<int> IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>::Process(const std::vector<std::string> input)
	{
		std::vector<int> intList;

		if (!input.empty())
		{
			std::istringstream iss = std::istringstream(input[0]);
			std::string valStr;

			while (std::getline(iss, valStr, ' '))
				intList.push_back(std::stoi(valStr));
		}

		return intList;
	}

	// IntArrayProcessor: converts input to 2D array structure
	std::vector<std::vector<int>> IntArrayProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::vector<int>> result;
		result.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(result),
			[](const std::string& line)
			{
				std::vector<int> ints;
				ints.reserve(line.size());
				std::transform(line.begin(), line.end(), std::back_inserter(ints), [](char c) { return c - '0'; });
				return ints;
			}
		);

		return result;
	}

	std::vector<uint64_t> LargeIntProcessor::Process(std::vector<std::string> input)
	{
		std::vector<uint64_t> lIntList;
		lIntList.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(lIntList), [](const std::string& s) { return std::stoull(s); });

		return lIntList;
	}
}