#include "Day04_PassportProcessing.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day04
{
	// ---------------------------------------------------------------------------
	// Day04_PassportProcessing
	// Process input data as passports
	// ---------------------------------------------------------------------------
	PassportProcessing::PassportProcessing() : DayT(4, "Passport Processing") {}

	// ---------------------------------------------------------------------------
	// GetResult
	// Calculate the number of valid passports in the input data
	// ---------------------------------------------------------------------------
	uint64_t PassportProcessing::ExecutePart1(std::vector<Passport> passports)
	{
		return std::count_if(passports.begin(), passports.end(), [](Passport p) { return p.IsValid(); });
	}
}