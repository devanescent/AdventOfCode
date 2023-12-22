#pragma once
#include "DayT.h"
#include "SandBrickProcessor.h"

namespace AdventOfCode::Year2023::Day22
{
	// ---------------------------------------------------------------------------
	// Day22: Sand Slabs
	// ---------------------------------------------------------------------------
	class SandSlabs : public DayT<SandBrickProcessor>
	{
	public:
		SandSlabs();

	protected:
		uint64_t ExecutePart1(std::vector<SandBrick> sandBricks) override;
		uint64_t ExecutePart2(std::vector<SandBrick> sandBricks) override;
	};
}
