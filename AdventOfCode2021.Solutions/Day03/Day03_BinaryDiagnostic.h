#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day03
{
	class BinaryDiagnostic : public Day<>
	{
	public:
		BinaryDiagnostic();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> diagReport) override;
		uint64_t ExecutePart2(std::vector<std::string> diagReport) override;

	private:
		enum class LifeSupportRatingValue
		{
			O2,
			CO2
		};

		uint64_t GetLifeSupportRating(std::vector<std::string>& report, LifeSupportRatingValue lsrVal);
	};
}