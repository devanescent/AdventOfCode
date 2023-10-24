#include "EnhancementRulesProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day21
{
	std::vector<EnhancementRule> EnhancementRulesProcessor::Process(std::vector<std::string> input)
	{
		std::vector<EnhancementRule> rules;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			std::string arrow;

			EnhancementRule rule;
			iss >> rule.InputPattern >> arrow;
			
			std::string outputPatternLine;
			while (std::getline(iss, outputPatternLine, '/'))
			{
				// Discard whitespace after the arrow:
				if (outputPatternLine[0] == ' ')
					outputPatternLine = outputPatternLine.substr(1);

				rule.OutputPattern.emplace_back(outputPatternLine);
			}

			rules.emplace_back(rule);
		}

		return rules;
	}
}
