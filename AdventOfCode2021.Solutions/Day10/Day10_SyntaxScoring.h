#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day10
{
	class SyntaxScoring : public Day
	{
	public:
		SyntaxScoring();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
	};

	uint64_t GetCorruptionScore(const std::string& chunkLine);
}