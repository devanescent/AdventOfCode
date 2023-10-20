#pragma once
#include "KnotHashCalculator.h"
#include <algorithm>
#include <functional>
#include <numeric>

namespace AdventOfCode::Year2017
{
	void RunKnotHashRound(std::vector<int>& numbers, const std::vector<int>& lengths, int& listStartIndex, int& skipSize)
	{
		for (auto len : lengths)
		{
			// Reverse the given length:
			std::reverse(numbers.begin(), numbers.begin() + len);

			// Instead of moving the current position, rotate the list,
			// so reverse operations do not wrap around
			int shift = (len + skipSize) % numbers.size();
			std::rotate(numbers.begin(), numbers.begin() + shift, numbers.end());

			// Keep track of actual list start:
			listStartIndex = (listStartIndex + numbers.size() - shift) % numbers.size();

			++skipSize;
		}
	}

	std::vector<int> CalculateKnotHash(const std::string& input, size_t numberLen)
	{
		// Convert input to sequence of ASCII codes:
		std::vector<int> lengths(input.begin(), input.end());

		// Add suffix values:
		std::vector<int> lengthSuffix{ 17, 31, 73, 47, 23 };
		lengths.insert(lengths.end(), lengthSuffix.begin(), lengthSuffix.end());

		// Run knot hash 64 times:
		std::vector<int> numbers(numberLen);
		std::iota(numbers.begin(), numbers.end(), 0);

		int listStartIndex = 0;
		int skipSize = 0;

		for (int i = 0; i < 64; ++i)
			RunKnotHashRound(numbers, lengths, listStartIndex, skipSize);

		// Rotate again to re-assign the list start index to the actual beginning of the list:
		std::rotate(numbers.begin(), numbers.begin() + listStartIndex, numbers.end());

		// Calculate dense hash:
		std::vector<int> denseHash;
		for (int i = 0; i < 16; ++i)
		{
			denseHash.push_back(std::accumulate(
				numbers.begin() + (16 * i),
				numbers.begin() + (16 * (i + 1)),
				0,
				std::bit_xor()));
		}

		return denseHash;
	}
}
