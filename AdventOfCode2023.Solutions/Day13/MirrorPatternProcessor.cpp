#include "MirrorPatternProcessor.h"

namespace AdventOfCode::Year2023::Day13
{
	std::vector<MirrorPattern> MirrorPatternProcessor::Process(std::vector<std::string> input)
	{
		std::vector<MirrorPattern> mirrorPatterns;

		MirrorPattern pattern;
		for (const std::string& line : input)
		{
			if (!line.empty())
				pattern.Data.push_back(line);
			else
			{
				mirrorPatterns.emplace_back(pattern);
				pattern = MirrorPattern();
			}
		}

		mirrorPatterns.emplace_back(pattern);
		return mirrorPatterns;
	}
}
