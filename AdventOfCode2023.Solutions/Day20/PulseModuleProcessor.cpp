#include "PulseModuleProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day20
{
	std::vector<PulseModule> PulseModuleProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PulseModule> modules;

		for (const auto& line : input)
		{
			std::istringstream iss(line);
			PulseModule module;

			iss >> module.Name;
			if (module.Name == "broadcaster")
				module.ModuleType = PulseModuleType::Broadcaster;
			else
			{
				if (module.Name[0] == '%')
					module.ModuleType = PulseModuleType::FlipFlop;
				else if (module.Name[0] == '&')
					module.ModuleType = PulseModuleType::Conjunction;

				// Remove prefix:
				module.Name = module.Name.substr(1);
			}

			std::string destination;
			iss >> destination; // ignore "->"
			while (iss >> destination)
			{
				if (destination.back() == ',')
					destination.pop_back();
				module.Destinations.emplace_back(destination);
			}

			modules.emplace_back(module);
		}

		return modules;
	}
}
