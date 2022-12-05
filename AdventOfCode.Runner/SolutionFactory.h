#pragma once
#include "Solutions.h"

namespace AdventOfCode
{
	class SolutionFactory
	{
	public:
		std::unique_ptr<Solutions> GetYear(int year);
	};
}


