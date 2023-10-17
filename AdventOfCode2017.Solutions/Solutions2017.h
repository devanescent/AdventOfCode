#pragma once
#include <memory>
#include "Solutions.h"

namespace AdventOfCode::Year2017
{
	class Solutions2017 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				default:	return nullptr;
			}
		}
	};
}

