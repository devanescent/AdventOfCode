#include "PasswortPolicyProcessor.h"
#include <regex>

namespace AdventOfCode::Year2020::Day02
{
	// Policy given in format: 1-3 a: abcde
	std::vector<PasswordPolicy> PasswortPolicyProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PasswordPolicy> policies;
		policies.reserve(input.size());

		std::regex policyPattern = std::regex("([0-9]+)-([0-9]+) ([a-z]{1}): ([a-z]+)");
		std::smatch matches;

		for (std::string line : input)
		{
			// Number of matches == 5: the whole string plus all 4 capture groups
			if (std::regex_search(line, matches, policyPattern) && matches.size() == 5)
			{
				char requiredLetter = matches[3].str()[0];
				int minOcc = atoi(matches[1].str().c_str());
				int maxOcc = atoi(matches[2].str().c_str());
				std::string pw = matches[4].str();

				policies.push_back(PasswordPolicy(requiredLetter, minOcc, maxOcc, pw));
			}
		}

		return policies;
	}
}
