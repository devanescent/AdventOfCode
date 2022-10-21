#include "MessageRuleProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2020::Day19
{
	std::pair<std::vector<std::string>, MessageRuleCollection> MessageRuleProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<std::string>, MessageRuleCollection> result;

		// Rules and messages are separated by empty line:
		// First part: rules
		auto lineIt = input.begin();
		for (lineIt; !lineIt->empty(); ++lineIt)
		{
			std::istringstream iss(*lineIt);
			std::string ruleToken;

			auto ruleID = std::strtol(lineIt->c_str(), nullptr, 10);
			iss >> ruleToken; // discard <ruleId> + colon

			if (lineIt->find('"') != std::string::npos)
			{
				// Rule is a literal:
				iss >> ruleToken;
				result.second.AddRule(ruleID, MessageRule(ruleToken[1])); // Token will be in the form '"x"'
			}
			else
			{
				// Get all subrules and alternatives:
				std::vector<std::vector<int>> subRuleAlternatives;
				std::vector<int> subRule;

				while (iss >> ruleToken)
				{
					if (ruleToken == "|")
					{
						// Option:
						subRuleAlternatives.emplace_back(subRule);
						subRule.clear();
					}
					else
					{
						// Reference to another rule:
						subRule.emplace_back(atoi(ruleToken.c_str()));
					}
				}

				// Finish rule and register:
				subRuleAlternatives.emplace_back(subRule);
				result.second.AddRule(ruleID, MessageRule(subRuleAlternatives));
			}
		}

		 // Second part: messages:
		result.first = std::vector<std::string>(lineIt + 1, input.end()); // +1 to skip the empty line

		return result;
	}
}