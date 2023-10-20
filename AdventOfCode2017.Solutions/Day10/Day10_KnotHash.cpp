#include "Day10_KnotHash.h"
#include "KnotHashCalculator.h"
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
		// Calculate knot hash:
		std::vector<int> denseHash = CalculateKnotHash(input[0], m_numberListLength);

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
}
