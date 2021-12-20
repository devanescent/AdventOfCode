#include "TrenchImageProcessor.h"

namespace AdventOfCode::Year2021::Day20
{
	std::pair<std::vector<std::string>, std::string> TrenchImageProcessor::Process(std::vector<std::string> input)
	{
		// First line: image enhancement algorithm
		// After one empty line, the rows of the actual input image
		return std::make_pair(std::vector<std::string>(input.begin() + 2, input.end()), *input.begin());
	}
}