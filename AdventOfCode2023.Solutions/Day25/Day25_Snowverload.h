#pragma once
#include "DayT.h"
#include "ComponentWiringProcessor.h"

namespace AdventOfCode::Year2023::Day25
{
	// ---------------------------------------------------------------------------
	// Day25: Snowverload
	// ---------------------------------------------------------------------------
	class Snowverload : public DayT<ComponentWiringProcessor>
	{
	public:
		Snowverload();

	protected:
		uint64_t ExecutePart1(std::vector<Wiring> components) override;
	};
}
