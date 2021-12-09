#pragma once
#include "DayT.h"

namespace AdventOfCode::Year2021::Day03
{
	class BinaryDiagnostic : public Day
	{
	public:
		BinaryDiagnostic();

		uint64_t GetResultOnPart1(std::vector<std::string> diagReport) override;
	};
}