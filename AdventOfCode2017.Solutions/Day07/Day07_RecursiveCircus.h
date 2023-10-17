#pragma once
#include "DayT.h"
#include "TowerProgramProcessor.h"

namespace AdventOfCode::Year2017::Day07
{
	// ---------------------------------------------------------------------------
	// Day07: Recursive Circus
	// ---------------------------------------------------------------------------
	class RecursiveCircus : public DayT<TowerProgramProcessor>
	{
	public:
		RecursiveCircus();

	protected:
		uint64_t ExecutePart1(std::vector<TowerProgram> prgms) override;
		uint64_t ExecutePart2(std::vector<TowerProgram> prgms) override;

	private:
		std::string GetBasePrgmName(std::vector<TowerProgram>& prgms);
	};
}
