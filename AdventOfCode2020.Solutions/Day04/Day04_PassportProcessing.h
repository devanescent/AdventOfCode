#pragma once
#include "DayT.h"
#include "Passport.h"
#include "PassportProcessor.h"

namespace AdventOfCode::Year2020::Day04
{
	class PassportProcessing : public DayT<PassportProcessor>
	{
	public:
		PassportProcessing();

	protected:
		uint64_t ExecutePart1(std::vector<Passport> passports) override;
	};
}