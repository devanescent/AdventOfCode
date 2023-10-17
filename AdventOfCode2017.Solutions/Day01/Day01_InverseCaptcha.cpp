#include "Day01_InverseCaptcha.h"
#include <numeric>

namespace AdventOfCode::Year2017::Day01
{
	InverseCaptcha::InverseCaptcha() : Day(1, "Inverse Captcha") { }

	uint64_t InverseCaptcha::GetResultOnPart1(std::vector<std::string> input)
	{
		std::vector<int> digitsToAdd;

		const std::string& sequence = input[0];
		std::adjacent_difference(sequence.cbegin(), sequence.cend(), std::back_inserter(digitsToAdd),
			[](char c1, char c2) { return c1 == c2 ? (c1 - '0') : 0; });

		// Circular check:
		if (*sequence.begin() == *(sequence.end() - 1))
			digitsToAdd.push_back((*sequence.begin()) - '0');

		// Ignore the first element that was copied by std::adjacent_difference
		return std::accumulate(digitsToAdd.begin() + 1, digitsToAdd.end(), 0ull);
	}

	uint64_t InverseCaptcha::GetResultOnPart2(std::vector<std::string> input)
	{
		const std::string& sequence = input[0];

		// Only iterate half the list, because comparisons are symmetrical:
		uint64_t sum = 0ull;
		int halfLen = sequence.size() / 2;
		for (int i = 0; i < halfLen; ++i)
		{
			if (sequence[i] == sequence[i + halfLen])
				sum += 2ull * (sequence[i] - '0');
		}

		return sum;
	}
}
