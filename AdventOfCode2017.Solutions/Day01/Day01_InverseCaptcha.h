#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day01
{
	// ---------------------------------------------------------------------------
	// Day01: Inverse Captcha
	// ---------------------------------------------------------------------------
	class InverseCaptcha : public Day<>
	{
	public:
		InverseCaptcha();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};
}
