#pragma once
#include "DayTC.h"
#include "DebugInfoProcessor.h"

namespace AdventOfCode::Year2024::Day17
{
	// ---------------------------------------------------------------------------
	// Day17: Chronospatial Computer
	// ---------------------------------------------------------------------------
	class ChronospatialComputer : public DayTC<DebugInfoProcessor, std::string>
	{
	public:
		ChronospatialComputer();

	protected:
		std::string ExecutePart1(std::vector<int> program, Registers reg) override;
		std::string ExecutePart2(std::vector<int> program, Registers reg) override;

	private:
		std::string ExecuteProgram(Registers reg) const;
		bool AddNextDigit(const std::string& originalProgram, Registers reg, uint64_t currentResult, uint64_t& finalResult) const;

		std::vector<int> _program;
	};
}
