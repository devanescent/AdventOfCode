#pragma once
#include <string>
#include <vector>

namespace AdventOfCode::Year2017
{
	void RunKnotHashRound(std::vector<int>& numbers, const std::vector<int>& lengths, int& listStartIndex, int& skipSize);
	std::vector<int> CalculateKnotHash(const std::string& input, size_t numberLen = 256);
}
