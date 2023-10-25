#pragma once
#include "DayT.h"
#include "MagneticComponentProcessor.h"

namespace AdventOfCode::Year2017::Day24
{
	// ---------------------------------------------------------------------------
	// Day24: Electromagnetic Moat
	// ---------------------------------------------------------------------------
	class ElectromagneticMoat : public DayT<MagneticComponentProcessor>
	{
	public:
		ElectromagneticMoat();

	protected:
		uint64_t ExecutePart1(std::vector<MagneticComponent> components) override;
		uint64_t ExecutePart2(std::vector<MagneticComponent> components) override;
	};
}
