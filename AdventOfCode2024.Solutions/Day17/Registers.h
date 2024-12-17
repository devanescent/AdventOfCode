#pragma once
#include "OpCode.h"
#include <cmath>

namespace AdventOfCode::Year2024::Day17
{
	struct Registers
	{
		uint64_t A = 0;
		uint64_t B = 0;
		uint64_t C = 0;

		uint64_t GetComboOperand(int operand)
		{
			switch (operand)
			{
				case 0: case 1: case 2: case 3:
					return operand;
				case 4:
					return A;
				case 5:
					return B;
				case 6:
					return C;
				default:
					return 0;
			}
		}
	};
}
