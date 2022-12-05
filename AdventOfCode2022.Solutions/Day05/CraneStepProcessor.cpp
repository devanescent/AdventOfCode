#include "CraneStepProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2022::Day05
{
	std::pair<std::vector<CraneStep>, CrateStacks> CraneStepProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<CraneStep>, CrateStacks> result;

		// First part: starting arrangement of crates:
		CrateStacks& stacks = result.second;

		// Process crate stacks from the bottom up: find empty line
		auto emptyLineIt = std::find(input.begin(), input.end(), "");
		auto stacksStartIt = std::make_reverse_iterator(emptyLineIt - 1);
		// -> reverse iterator points to the element before it, so from the empty line move up just once to point to the bottom of the stacks

		for (auto lineIt = stacksStartIt; lineIt != input.rend(); ++lineIt)
		{
			int crateIx = 0;
			while (1 + crateIx * 4 < lineIt->length()) // letter inside of each '[ ]'
			{
				char crateContent = (*lineIt)[1 + crateIx * 4];

				// Add new 'column':
				if (crateIx == stacks.size())
					stacks.emplace_back(std::stack<char>());

				// Add crate on top of a stack:
				if (crateContent != ' ')
					stacks[crateIx].push(crateContent);

				++crateIx;
			}
		}

		// Second part: move instructions for the crane:
		std::vector<CraneStep>& steps = result.first;
		steps.reserve(input.size());

		for (auto stepIt = emptyLineIt + 1; stepIt != input.end(); ++stepIt)
		{
			CraneStep step;

			std::stringstream iss(*stepIt);
			std::string ignore;

			iss >> ignore /*move*/ >> step.NoOfCrates >> ignore /*from*/ >> step.FromStack >> ignore /*to*/ >> step.ToStack;
			steps.emplace_back(step);
		}

		return result;
	}
}
