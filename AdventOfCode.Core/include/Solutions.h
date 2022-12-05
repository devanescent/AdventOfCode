#pragma once
#include <memory>
#include "Day.h"

namespace AdventOfCode
{
	// Base class for each year's solutions
	class Solutions
	{
	public:
		virtual std::unique_ptr<Day> GetDay(int day) = 0;
	};
}

