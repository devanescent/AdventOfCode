#pragma once
#include <map>
#include <string>
#include <vector>

namespace AdventOfCode::Year2020::Day19
{
	class MessageRule
	{
	public:
		// Pattern that matches this rule:
		std::string Pattern;

		// Structure of this rule: which subrules / alternatives it consists of:
		std::vector<std::vector<int>> SubRuleAlternatives;

		MessageRule(std::vector<std::vector<int>> subRules) : SubRuleAlternatives(std::move(subRules)) {}
		MessageRule(char matchingChar) : Pattern(1, matchingChar) {}
		MessageRule(std::string pattern) : Pattern(std::move(pattern)) {}

		bool HasPattern() const
		{
			return !Pattern.empty();
		}
	};

	class MessageRuleCollection
	{
	private:
		std::map<int, MessageRule> m_rules;

	public:
		void AddRule(int id, MessageRule rule)
		{
			m_rules.emplace(id, rule);
		}

		void UpdateRule(int id, MessageRule rule)
		{
			m_rules.at(id) = rule;
		}

		// Gets the resulting regex pattern from a rule
		// (will recursively process other rules as necessary)
		const std::string& GetRulePattern(int ruleId)
		{
			MessageRule& rule = m_rules.at(ruleId);
			if (!rule.HasPattern())
			{
				// Pattern has not been built yet: construct it
				for (const std::vector<int>& subRule : rule.SubRuleAlternatives)
				{
					if (!rule.Pattern.empty())
						rule.Pattern.append("|");

					for (int subRuleId : subRule)
					{
						rule.Pattern.append(GetRulePattern(subRuleId));
					}
				}

				// Group pattern: non-capturing group
				if (rule.SubRuleAlternatives.size() > 1)
					rule.Pattern = "(?:" + rule.Pattern + ")";
			}

			return rule.Pattern;
		}
	};
}