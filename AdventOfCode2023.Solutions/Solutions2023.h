#pragma once
#include <memory>
#include "Solutions.h"

namespace AdventOfCode::Year2023
{
	class Solutions2023 : public Solutions
	{
		std::unique_ptr<DayBase> GetDay(int day) override
		{
			switch (day)
			{
				default:	return nullptr;
			}
		}
	};
}

