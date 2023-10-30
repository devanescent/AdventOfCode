#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day10
{
	class SyntaxScoring : public Day<>
	{
	public:
		SyntaxScoring();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;
	};

	std::pair<uint64_t, uint64_t> GetScore(const std::string& chunkLine);
}