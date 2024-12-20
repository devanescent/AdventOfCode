#pragma once
#include <vector>

namespace AdventOfCode::Year2024::Day07
{
	class Calibration
	{
	public:
		uint64_t TestValue = 0;
		std::vector<int> EquationValues;
		
		bool IsValid = false;
	};
}
