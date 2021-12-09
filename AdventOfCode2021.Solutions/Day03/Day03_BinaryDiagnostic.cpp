#include "Day03_BinaryDiagnostic.h"
#include <numeric>
#include <cmath>

namespace AdventOfCode::Year2021::Day03
{
	BinaryDiagnostic::BinaryDiagnostic() : Day(3, "Binary Diagnostic") {}

	uint64_t BinaryDiagnostic::GetResultOnPart1(std::vector<std::string> diagReport)
	{
		if (!diagReport.empty())
		{
			// Assume, all numbers are of the same length:
			size_t bitNumLen = diagReport[0].length();

			// Count number of set bits in each position:
			std::vector<size_t> bitCounts(bitNumLen);
			for (const std::string& bitNum : diagReport)
			{
				for (size_t i = 0; i < bitNum.length(); ++i)
					bitCounts[i] += (bitNum[i] == '1' ? 1 : 0);
			}

			// Calculate gamma rate:
			// Each bit is set to the value that occured the most at its position in the input data set:
			uint64_t gammaRate = 0ull;
			for (size_t i = 0; i < bitCounts.size(); ++i)
			{
				// Bit at index i (counted from the right), if more than half of the bits of the input data were set
				if (bitCounts[bitCounts.size() - 1 - i] > (diagReport.size() / 2))
					gammaRate += static_cast<unsigned long long>(std::pow(2.0, i));
			}

			// Invert bits to calculate epsilon rate - use mask to set upper (unused bits) to zero:
			uint64_t mask = static_cast<uint64_t>(std::pow(2.0, bitNumLen)) - 1;
			uint64_t epsilonRate = ~gammaRate & mask;

			return gammaRate * epsilonRate;
		}

		return 0ull;
	}
}
