#include "ValveProcessor.h"
#include <regex>

namespace AdventOfCode::Year2022::Day16
{
	std::map<std::string, Valve> ValveProcessor::Process(std::vector<std::string> input)
	{
		std::map<std::string, Valve> valves;

		// Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE
		std::regex flowPattern = std::regex("flow rate=([0-9]+);");
		std::regex namePattern = std::regex("([A-Z]{2})");
		std::smatch matches;

		for (const std::string& line : input)
		{
			Valve v;

			std::regex_search(line, matches, flowPattern);
			v.FlowRate = std::stoi(matches[1].str());

			// First name belongs to valve itself, the following ones are valves it's connected to:
			std::regex_search(line, matches, namePattern);
			v.Name = matches[1].str();

			std::string restOfLine = matches.suffix();
			while (std::regex_search(restOfLine, matches, namePattern))
			{
				v.ConnectedValves.emplace_back(matches[1].str());
				restOfLine = matches.suffix();
			}

			valves.emplace(v.Name, std::move(v));
		}

		return valves;
	}
}
