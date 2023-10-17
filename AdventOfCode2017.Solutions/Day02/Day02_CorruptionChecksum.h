#pragma once
#include "DayT.h"
#include "SpreadsheetProcessor.h"

namespace AdventOfCode::Year2017::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Corruption Checksum
	// ---------------------------------------------------------------------------
	class CorruptionChecksum : public DayT<SpreadsheetProcessor>
	{
	public:
		CorruptionChecksum();

	protected:
		uint64_t ExecutePart1(std::vector<std::vector<int>> spreadsheet) override;
		uint64_t ExecutePart2(std::vector<std::vector<int>> spreadsheet) override;

	private:
		int GetEvenlyDivisibleResult(const std::vector<int>& spreadsheetRow);
	};
}
