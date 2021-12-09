#pragma once
#include "DayT.h"
#include "Passport.h"
#include "PassportProcessor.h"

namespace AdventOfCode::Year2020::Day04
{
	class PassportProcessing : public DayT<Passport, PassportProcessor>
	{
	public:
		PassportProcessing();

	protected:
		uint64_t ExecutePart1(std::vector<Passport> passports) override;
	};
}