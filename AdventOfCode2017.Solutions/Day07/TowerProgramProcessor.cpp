#include "TowerProgramProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day07
{
	std::vector<TowerProgram> TowerProgramProcessor::Process(std::vector<std::string> input)
	{
		std::vector<TowerProgram> programs;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			
			TowerProgram tp;

			// Name:
			iss >> tp.Name;

			// Weight:
			std::string weightStr;
			iss >> weightStr;
			tp.Weight = std::stoi(weightStr.substr(1, weightStr.length() - 2));

			std::string balancedPrgm;
			if (iss >> balancedPrgm) // will also discard the "->"
			{
				while (iss >> balancedPrgm)
				{
					if (balancedPrgm.ends_with(','))
						balancedPrgm.pop_back();

					tp.BalancedPrgmNames.emplace_back(balancedPrgm);
				}
			}

			programs.emplace_back(tp);
		}

		return programs;
	}
}
