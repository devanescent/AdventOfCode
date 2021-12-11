#pragma once
#include "DayT.h"
#include "DiveCmd.h"
#include "DiveCmdProcessor.h"

namespace AdventOfCode::Year2021::Day02
{

	class DivePos
	{
	public:
		int HorizontalPosition = 0;
		int Depth = 0;
		int Aim = 0;
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
		uint64_t ExecutePart2(std::vector<DiveCmd> course) override;
	};
}