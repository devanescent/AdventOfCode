#include "Day19_MonsterMessages.h"
#include <regex>

namespace AdventOfCode::Year2020::Day19
{
	MonsterMessages::MonsterMessages() : DayTC(19, "Monster Messages") {}

	uint64_t MonsterMessages::ExecutePart1(std::vector<std::string> messages, MessageRuleCollection rules)
	{
		// Build regex from rule 0: (whole message must match)
		auto ruleRegex = std::regex("^" + rules.GetRulePattern(0) + "$");

		uint64_t validMessages = std::count_if(messages.begin(), messages.end(),
			[&ruleRegex](const std::string& msg)
			{
				return std::regex_match(msg, ruleRegex);
			});

		return validMessages;
	}

	uint64_t MonsterMessages::ExecutePart2(std::vector<std::string> messages, MessageRuleCollection rules)
	{
		// Assume, rule 0 is exactly: 8 11

		// Change patterns:
		// To fix them, completely replace rules 8 and 11 with the following:

		// 8: 42 | 42 8 -> 42+
		rules.UpdateRule(8, MessageRule("(" + rules.GetRulePattern(42) + "+)")); // multiple repetitions of pattern 42
		// -> also capture as this will overlap with the pattern for rule 11 below

		// 11: 42 31 | 42 11 31 -> 42+31+, with the same count on both sides
		// Because Regex cannot detect patterns line a{n}b{n}, capture both halves with a group
		// and check number of repetitions manually:
		rules.UpdateRule(11, MessageRule(
			"((?:" + rules.GetRulePattern(42) + ")+)" +
			"((?:" + rules.GetRulePattern(31) + ")+)"
		));

		// Build regex from rule 0: (whole message must match)
		std::regex regex_0("^" + rules.GetRulePattern(0) + "$");

		std::regex regex_42(rules.GetRulePattern(42));
		std::regex regex_31(rules.GetRulePattern(31));

		uint64_t validMessages = std::count_if(messages.begin(), messages.end(),
			[&](const std::string& msg)
			{
				std::smatch matches;
				if (std::regex_search(msg, matches, regex_0))
				{
					// Check capture groups:
					std::smatch captureMatches;

					// First capture: repetition of rule 42 from rule 8: This is greedy and will therefore overlap with rule 11:
					std::string rule42Capture = matches[1];
					int count42 = 0;
					while (std::regex_search(rule42Capture, captureMatches, regex_42))
					{
						++count42;
						rule42Capture = captureMatches.suffix();
					}

					// Second capture will be the one remaining match of rule 42 becuase of the '+' quantifier in rule 11
					++count42;

					// Third capture: repetition of rule 31:					
					std::string rule31Capture = matches[3].str();
					int count31 = 0;
					while (std::regex_search(rule31Capture, captureMatches, regex_31))
					{
						++count31;
						rule31Capture = captureMatches.suffix();
					}

					// Number of rule-42-matches must be larger than number of rule-31-matches
					// Any excess rule-42-matches (must be at least 1) are matched by rule 8
					return count42 > count31;
				}

				return false;
			});

		return validMessages;
	}
}


