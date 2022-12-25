#include "SNAFUProcessor.h"

namespace AdventOfCode::Year2022::Day25
{
	std::vector<SNAFUNumber> SNAFUProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SNAFUNumber> numbers;

		for (std::string& line : input)
		{
			// Process reversed:
			std::reverse(line.begin(), line.end());

			uint64_t factor = 1;
			int64_t number = 0;
			for (char c : line)
			{
				switch (c)
				{
					case '1': number += factor; break;
					case '2': number += 2 * factor; break;
					case '-': number -= factor; break;
					case '=': number -= factor * 2; break;
				}
				factor *= 5;
			}

			numbers.emplace_back(number);
		}

		return numbers;
	}
}
