#include "Day04_PassportProcessing.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day04
{
	PassportProcessing::PassportProcessing() : DayT(4, "Passport Processing") {}

	uint64_t PassportProcessing::ExecutePart1(std::vector<Passport> passports)
	{
		return std::count_if(passports.begin(), passports.end(), [](Passport p) { return p.IsValid(Passport::ValidateData::Disabled); });
	}

	uint64_t PassportProcessing::ExecutePart2(std::vector<Passport> passports)
	{
		return std::count_if(passports.begin(), passports.end(), [](Passport p) { return p.IsValid(Passport::ValidateData::Enabled); });
	}
}