#include "BlueprintsProcessor.h"
#include <regex>

namespace AdventOfCode::Year2017::Day25
{
	std::string GetRegexGroupFromLine(std::vector<std::string>::iterator& lineIt, const std::string& regexWithSingleGroup)
	{
		std::smatch matches;

		std::regex pattern = std::regex(regexWithSingleGroup);
		std::regex_search(*lineIt, matches, pattern);
		++lineIt;

		return matches[1].str();
	}

	void FillBlueprintFields(Blueprint& b, std::vector<std::string>::iterator& lineIt)
	{
		b.ValueCondition = std::stoi(GetRegexGroupFromLine(lineIt, "If the current value is (0|1):"));
		b.ValueWritten = std::stoi(GetRegexGroupFromLine(lineIt, "Write the value (0|1)."));
		b.CursorMovement = GetRegexGroupFromLine(lineIt, "Move one slot to the (right|left).") == "right" ? CursorMovement::Right : CursorMovement::Left;
		b.NextState = GetRegexGroupFromLine(lineIt, "Continue with state ([A-Z]).")[0];
	}

	std::pair<std::vector<Blueprint>, BlueprintInitializer> BlueprintsProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Blueprint>, BlueprintInitializer> result;
		std::vector<Blueprint>& blueprints = result.first;
		BlueprintInitializer& initializer = result.second;

		auto lineIt = input.begin();
		initializer.State = GetRegexGroupFromLine(lineIt, "Begin in state ([A-Z]).")[0];
		initializer.Steps = std::stoull(GetRegexGroupFromLine(lineIt, "Perform a diagnostic checksum after ([0-9]+) steps."));
		
		while (lineIt != input.end())
		{
			++lineIt; // empty line between states

			// For each state there are two blueprints
			Blueprint b1, b2;

			b1.StateCondition = b2.StateCondition = GetRegexGroupFromLine(lineIt, "In state ([A-Z]):")[0];
			FillBlueprintFields(b1, lineIt);
			FillBlueprintFields(b2, lineIt);

			blueprints.emplace_back(b1);
			blueprints.emplace_back(b2);
		}

		return result;
	}
}
