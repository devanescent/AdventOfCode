#include "Day10_AdapterArray.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day10 
{
	AdapterArray::AdapterArray() : DayT(10, "Adapter Array") {}

	uint64_t Day10::AdapterArray::ExecutePart1(std::vector<int> input)
	{
		// Wall adapter:
		input.push_back(0);

		// built-in adapter: max + 3:
		input.push_back(*(std::max_element(input.begin(), input.end())) + 3);

		// to use all adapters, they have to be used in ordered series:
		std::sort(input.begin(), input.end());

		// count differences of 1 and 3 joltages:
		int dif1 = 0;
		int dif3 = 0;
		for (int i = 1; i < (int)input.size(); ++i)
		{
			int dif = input[i] - input[i - 1];
			if (dif == 1)
				dif1++;
			else if (dif == 3)
				dif3++;
		}

		return dif1 * dif3;
	}
}