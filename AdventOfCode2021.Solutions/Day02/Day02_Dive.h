#pragma once
#include "DayT.h"
#include "DivePos.h"
#include "DiveCmd.h"
#include "DiveCmdProcessor.h"

namespace AdventOfCode::Year2021::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Dive! 
	// ---------------------------------------------------------------------------
	class Dive : public DayT<DiveCmd, DiveCmdProcessor>
	{
	public:
		Dive();

	protected:
		uint64_t ExecutePart1(std::vector<DiveCmd> course) override;
		uint64_t ExecutePart2(std::vector<DiveCmd> course) override;

	private:
		void ApplyCourse(const std::vector<DiveCmd>& course, DivePos& initialPos);
	};
}