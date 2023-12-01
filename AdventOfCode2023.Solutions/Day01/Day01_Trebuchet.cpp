#include "Day01_Trebuchet.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2023::Day01
{
	Trebuchet::Trebuchet() : Day(1, "Trebuchet") { }

	const std::vector<char> digits{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	const std::vector<std::string> digitsAndNames
	{
		"1", "2", "3", "4", "5", "6", "7", "8", "9",
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	uint64_t Trebuchet::ExecutePart1(std::vector<std::string> input)
	{
		return std::accumulate(input.begin(), input.end(), 0ull,
			[](uint64_t sum, const std::string& line)
			{
				auto firstDigit = std::find_first_of(line.begin(), line.end(), digits.begin(), digits.end());
				auto lastDigit = std::find_first_of(line.rbegin(), line.rend(), digits.begin(), digits.end());

				return sum + (*firstDigit - '0') * 10 + (*lastDigit - '0');
			});
	}

	uint64_t Trebuchet::ExecutePart2(std::vector<std::string> input)
	{
		uint64_t sum = 0;
		for (const std::string& line : input)
		{
			auto firstDigitPos = line.size();
			auto lastDigitPos = 0;

			int firstDigitVal = 0;
			int lastDigitVal = 0;

			for (int i = 0; i < digitsAndNames.size(); ++i)
			{
				// Find first digit, keep track of the leftmost value:
				auto firstDigit = line.find(digitsAndNames[i]);
				if (firstDigit != std::string::npos && firstDigit < firstDigitPos)
				{
					firstDigitPos = firstDigit;
					firstDigitVal = i < 9 ? i + 1 : i - 8; // map from list index to actual value
				}

				// Find last digit, keep track of the rightmost value:
				auto lastDigit = line.rfind(digitsAndNames[i]);
				if (lastDigit != std::string::npos && lastDigit + 1 > lastDigitPos)
				{
					lastDigitPos = lastDigit + 1;
					lastDigitVal = i < 9 ? i + 1 : i - 8; // map from list index to actual value
				}
			}

			sum += firstDigitVal * 10 + lastDigitVal;
		}

		return sum;
	}
}
