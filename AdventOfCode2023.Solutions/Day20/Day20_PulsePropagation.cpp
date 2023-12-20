#include "Day20_PulsePropagation.h"
#include <queue>

namespace AdventOfCode::Year2023::Day20
{
	PulsePropagation::PulsePropagation() : DayT(20, "Pulse Propagation") { }

	uint64_t PulsePropagation::ExecutePart1(std::vector<PulseModule> modules)
	{
		std::map<std::string, PulseModule*> modulesByName;
		for (auto& module : modules)
			modulesByName[module.Name] = &module;

		// Initialize memory of conjunction modules:
		for (auto& conjMod : modules)
		{
			if (conjMod.ModuleType == PulseModuleType::Conjunction)
			{
				// Find all modules that have this module in their destination list:
				std::vector<std::string> inputs;
				for (auto& module : modules)
				{
					auto inputIt = std::find(module.Destinations.begin(), module.Destinations.end(), conjMod.Name);
					if (inputIt != module.Destinations.end())
						inputs.push_back(module.Name);
				}
				conjMod.InitializeMemory(inputs);
			}
		}

		// Count pulses:
		uint64_t lowPulseCount = 0, highPulseCount = 0;

		for (int i = 0; i < 1000; ++i)
		{
			// Send low pulse from button to broadcaster (from button press)
			std::queue<Pulse> pulseQueue;
			pulseQueue.emplace("button", "broadcaster", false);

			while (!pulseQueue.empty())
			{
				Pulse pulse = pulseQueue.front();
				pulseQueue.pop();

				if (pulse.High)
					++highPulseCount;
				else
					++lowPulseCount;

				auto receiverIt = modulesByName.find(pulse.To);
				if (receiverIt != modulesByName.end())
				{
					for (auto&& nextPulse : receiverIt->second->ReceivePulse(pulse))
					{
						pulseQueue.emplace(nextPulse);
					}
				}
			}
		}

		return lowPulseCount * highPulseCount;
	}

	uint64_t PulsePropagation::ExecutePart2(std::vector<PulseModule> modules)
	{
		return uint64_t{};
	}
}
