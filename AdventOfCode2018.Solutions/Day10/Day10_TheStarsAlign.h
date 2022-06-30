#pragma once
#include "DayT.h"
#include "PointOfLightProcessor.h"

namespace AdventOfCode::Year2018::Day10
{
	// ---------------------------------------------------------------------------
	// Day10: The Stars Align
	// ---------------------------------------------------------------------------
	class TheStarsAlign : public DayT<PointOfLightProcessor>
	{
	public:
		TheStarsAlign();
	
	protected:
		uint64_t ExecutePart1(std::vector<PointOfLight> points) override;
	};
}