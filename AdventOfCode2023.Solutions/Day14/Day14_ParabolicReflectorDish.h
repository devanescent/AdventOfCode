#pragma once
#include "DayTC.h"
#include "PlatformRocksProcessor.h"

namespace AdventOfCode::Year2023::Day14
{
	// ---------------------------------------------------------------------------
	// Day14: Parabolic Reflector Dish
	// ---------------------------------------------------------------------------
	class ParabolicReflectorDish : public DayTC<PlatformRocksProcessor>
	{
	public:
		ParabolicReflectorDish();

	protected:
		uint64_t ExecutePart1(std::vector<Rock> rocks, Platform platform) override;
		uint64_t ExecutePart2(std::vector<Rock> rocks, Platform platform) override;
	};
}
