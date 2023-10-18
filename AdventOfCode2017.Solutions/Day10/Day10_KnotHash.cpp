#include "Day10_KnotHash.h"
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <sstream>

namespace AdventOfCode::Year2017::Day10
{
	KnotHash::KnotHash() : DayT(10, "Knot Hash") { }

	uint64_t KnotHash::ExecutePart1(std::vector<int> lengths)
	{
		// Fill in numbers:
		std::vector<int> numbers(m_numberListLength);
		std::iota(numbers.begin(), numbers.end(), 0);

		int listStartIndex = 0;
		int skipSize = 0;

		RunKnotHashRound(numbers, lengths, listStartIndex, skipSize);

		// Multiply the first two numbers in the list, indicated by the listStartIndex:
		uint64_t result = numbers[listStartIndex];
		if (listStartIndex + 1 < m_numberListLength)
			result *= numbers[listStartIndex + 1];
		else
			result *= numbers[0]; // wrap around

		return result;
	}

	uint64_t KnotHash::GetResultOnPart2(std::vector<std::string> input)
	{
		// Convert input to sequence of ASCII codes:
		std::vector<int> lengths(input[0].begin(), input[0].end());
		
		// Add suffix values:
		std::vector<int> lengthSuffix{ 17, 31, 73, 47, 23 };
		lengths.insert(lengths.end(), lengthSuffix.begin(), lengthSuffix.end());

		// Run knot hash 64 times:
		std::vector<int> numbers(m_numberListLength);
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

		// Convert into string of hex digits:
		std::ostringstream oss;
		for (int denseHashNum : denseHash)
		{
			oss << std::setfill('0') << std::setw(2) // for leading zeroes
				<< std::hex << denseHashNum;		 // convert to hex representation
		}

		std::string hash = oss.str();
		return 0ull;
	}


	void KnotHash::RunKnotHashRound(std::vector<int>& numbers, const std::vector<int>& lengths, int& listStartIndex, int& skipSize)
	{
		for (auto len : lengths)
		{
			// Reverse the given length:
			std::reverse(numbers.begin(), numbers.begin() + len);

			// Instead of moving the current position, rotate the list,
			// so reverse operations do not wrap around
			int shift = (len + skipSize) % m_numberListLength;
			std::rotate(numbers.begin(), numbers.begin() + shift, numbers.end());

			// Keep track of actual list start:
			listStartIndex = (listStartIndex + m_numberListLength - shift) % m_numberListLength;

			++skipSize;
		}
	}
}
