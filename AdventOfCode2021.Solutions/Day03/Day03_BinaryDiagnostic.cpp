#include "Day03_BinaryDiagnostic.h"
#include <numeric>
#include <cmath>
#include <algorithm>

namespace AdventOfCode::Year2021::Day03
{
	BinaryDiagnostic::BinaryDiagnostic() : Day(3, "Binary Diagnostic") {}

	uint64_t BinaryDiagnostic::ExecutePart1(std::vector<std::string> diagReport)
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
					gammaRate += static_cast<uint64_t>(std::pow(2.0, i));
			}

			// Invert bits to calculate epsilon rate - use mask to set upper (unused bits) to zero:
			uint64_t mask = static_cast<uint64_t>(std::pow(2.0, bitNumLen)) - 1;
			uint64_t epsilonRate = ~gammaRate & mask;

			// Calculate power consumption:
			return gammaRate * epsilonRate;
		}

		return 0ull;
	}

	uint64_t BinaryDiagnostic::ExecutePart2(std::vector<std::string> diagReport)
	{
		if (!diagReport.empty())
		{
			uint64_t o2Rating = GetLifeSupportRating(diagReport, LifeSupportRatingValue::O2);
			uint64_t co2Rating = GetLifeSupportRating(diagReport, LifeSupportRatingValue::CO2);
			
			return o2Rating * co2Rating;
		}

		return 0ull;
	}


	uint64_t BinaryDiagnostic::GetLifeSupportRating(std::vector<std::string>& report, LifeSupportRatingValue lsrVal)
	{
		uint64_t rating = 0;
		
		// Initial range:
		auto resultRangeStart = report.begin();
		auto resultRangeEnd = report.end();

		// Iterate over the bits in each line
		size_t bitNumLen = report[0].length();
		for (size_t i = 0; i < bitNumLen; ++i)
		{
			// Sorts all lines that have a '0' in the respective bit to the front, the rest to the back
			auto midIt = std::partition(resultRangeStart, resultRangeEnd,
				[i, lsrVal](const std::string& line)
				{
					return line[i] == '0';
				}
			);

			if (lsrVal == LifeSupportRatingValue::O2)
			{
				// Continue searching in the half of the most common value (i.e. the larger half)
				// (or the half with the '1's, if both are of equal size):
				if (std::distance(resultRangeStart, midIt) > std::distance(midIt, resultRangeEnd))
					resultRangeEnd = midIt;		// first half is larger
				else
					resultRangeStart = midIt;	// second half is larger or both are equal (prefer '1')
			}
			else
			{
				// Continue searching in the half of the least common value (i.e. the smaller half)
				// (or the half with the '0's, if both are of equal size):
				if (std::distance(resultRangeStart, midIt) <= std::distance(midIt, resultRangeEnd))
					resultRangeEnd = midIt;		// first half is smaller or both are equal (prefer '0')
				else
					resultRangeStart = midIt;	// second half is smaller
			}
			

			// Last element left = calculate result
			if (std::distance(resultRangeStart, resultRangeEnd) == 1)
				return strtoull((*resultRangeStart).c_str(), nullptr, 2);
		}

		return 0ull;
	}
}
