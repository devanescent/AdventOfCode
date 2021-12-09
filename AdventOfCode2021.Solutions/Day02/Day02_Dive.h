#pragma once
#include "DayT.h"
#include "DiveCmd.h"
#include "DiveCmdProcessor.h"

namespace AdventOfCode::Year2021::Day02
{

	class DivePos
	{
	public:
		DivePos(int h = 0, int d = 0) : HorizontalPosition(h), Depth(d) {}

		int HorizontalPosition = 0;
		int Depth = 0;
	};

	// ---------------------------------------------------------------------------
	// Day01: Dive! 
	// ---------------------------------------------------------------------------
	class Dive : public DayT<DiveCmd, DiveCmdProcessor>
	{
	public:
		Dive();

	protected:
		uint64_t ExecutePart1(std::vector<DiveCmd> course) override;
	};
}