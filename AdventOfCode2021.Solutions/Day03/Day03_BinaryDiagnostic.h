#pragma once
#include "DayT.h"

namespace AdventOfCode::Year2021::Day03
{
	class BinaryDiagnostic : public Day
	{
	public:
		BinaryDiagnostic();

		uint64_t GetResultOnPart1(std::vector<std::string> diagReport) override;
		uint64_t GetResultOnPart2(std::vector<std::string> diagReport) override;

	private:
		enum class LifeSupportRatingValue
		{
			O2,
			CO2
		};

		uint64_t GetLifeSupportRating(std::vector<std::string>& report, LifeSupportRatingValue lsrVal);
	};
}