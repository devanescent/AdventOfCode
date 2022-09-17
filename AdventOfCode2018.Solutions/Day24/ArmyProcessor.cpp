#include "ArmyProcessor.h"
#include <regex>
#include <sstream>

namespace AdventOfCode::Year2018::Day24
{
	std::vector<Army> ArmyProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Army> armies; // Immune system & infection

		std::regex pattern("([0-9]+) units each with ([0-9]+) hit points (\\(.*\\))? ?with an attack that does ([0-9]+) ([a-z]+) damage at initiative ([0-9]+)");
		std::smatch matches;

		for (const std::string& line : input)
		{
			// Adds a new army:
			if (line == "Infection:" || line == "Immune System:")
				armies.push_back(Army());

			// Process unit groups:
			else if (std::regex_search(line, matches, pattern) && matches.size() == 7)
			{
				std::vector<std::string> weaknesses;
				std::vector<std::string> immunities;

				if (matches[3].matched)
				{
					std::istringstream weaknesses_immunities(matches[3].str());

					char delim;
					std::string resType, type, ignore;

					weaknesses_immunities >> delim; // opening '('
					while (true)
					{
						weaknesses_immunities >> resType; // weak | immune
						weaknesses_immunities >> ignore; // "to"

						// List of weaknesses / immunities
						while (true)
						{
							weaknesses_immunities >> type; // concrete element type

							delim = type.back(); // word is always delimited by either ')', ',' or ';'
							type.pop_back(); // remove delimiter

							if (resType == "weak")
								weaknesses.push_back(type);
							else
								immunities.push_back(type);

							if (delim == ')' || delim == ';')
								break;
						}

						if (delim == ')')
							break;
					}
				}

				UnitGroup grp(
					atoi(matches[1].str().c_str()),
					atoi(matches[2].str().c_str()),
					atoi(matches[4].str().c_str()),
					atoi(matches[6].str().c_str()),
					matches[5].str(),
					weaknesses,
					immunities
				);

				armies.back().AddUnitGroup(grp);
			}
		}

		return armies;
	}
}
