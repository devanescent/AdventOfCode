#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day10
{
	class SyntaxScoring : public Day
	{
	public:
		SyntaxScoring();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;
	};

	std::pair<uint64_t, uint64_t> GetScore(const std::string& chunkLine);
}