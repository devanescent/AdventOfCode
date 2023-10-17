#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: Inverse Captcha
	// ---------------------------------------------------------------------------
	class InverseCaptcha : public Day
	{
	public:
		InverseCaptcha();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};
}
