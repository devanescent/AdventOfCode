#include "Day01_InverseCaptcha.h"
#include "CharDigitConverter.h"
#include <numeric>

namespace AdventOfCode::Year2017::Day01
{
	InverseCaptcha::InverseCaptcha() : Day(1, "Inverse Captcha") { }

	uint64_t InverseCaptcha::ExecutePart1(std::vector<std::string> input)
	{
		std::string& sequence = input[0];

		// Append first element to the end for circular check:
		sequence.push_back(sequence.front());

		std::vector<int> digitsToAdd;
		digitsToAdd.reserve(sequence.size());

		std::adjacent_difference(sequence.begin(), sequence.end(), std::back_inserter(digitsToAdd),
			[](char c1, char c2) { return c1 == c2 ? CharToDigit<int>(c1) : 0; });

		// Ignore the first element that was copied by std::adjacent_difference
		return std::accumulate(digitsToAdd.begin() + 1, digitsToAdd.end(), 0ULL);
	}

	uint64_t InverseCaptcha::ExecutePart2(std::vector<std::string> input)
	{
		const std::string& sequence = input[0];

		// Only iterate half the list, because comparisons are symmetrical:
		uint64_t sum = 0ULL;

		auto halfLen = sequence.size() / 2;
		auto midpoint = sequence.cbegin() + halfLen;

		for (auto it = sequence.cbegin(); it != midpoint; ++it)
		{
			if (*it == *(it + halfLen))
				sum += CharToDigit<uint64_t>(*it) * 2;
		}

		return sum;
	}
}
