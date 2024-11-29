#pragma once
#include <memory>
#include "DayBase.h"

namespace AdventOfCode
{
	// Base class for each year's solutions
	class Solutions
	{
	public:
		virtual ~Solutions() = default;
		virtual std::unique_ptr<DayBase> GetDay(int day) = 0;
	};
}

