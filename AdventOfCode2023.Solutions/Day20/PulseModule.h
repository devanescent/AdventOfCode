#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace AdventOfCode::Year2023::Day20
{
	enum class PulseModuleType
	{
		FlipFlop,
		Conjunction,
		Broadcaster
	};

	struct Pulse
	{
		std::string From;
		std::string To;
		bool High;
	};

	class PulseModule
	{
	public:
		std::string Name;
		PulseModuleType ModuleType;

		// List of other modules this module sends pulses to:
		std::vector<std::string> Destinations;

	private:
		// Other values based on type:
		bool flipFlopOn = false; // only flipflop
		std::map<std::string, bool> memory; // only conjunction

	public:
		void InitializeMemory(std::vector<std::string> inputs)
		{
			if (ModuleType != PulseModuleType::Conjunction)
				return;

			// Initial state for each memory value is low pulse
			for (const auto& inp : inputs)
				memory[inp] = false;
		}

		std::vector<Pulse> ReceivePulse(const Pulse& pulse)
		{
			std::vector<Pulse> pulsesSent;

			switch (ModuleType)
			{
				case PulseModuleType::FlipFlop:
				{
					if (!pulse.High)
					{
						// Flips between off and on when receiving a low pulse
						flipFlopOn = !flipFlopOn;
						for (const auto& dest : Destinations)
							pulsesSent.emplace_back(Name, dest, flipFlopOn);
					}
					break;
				}

				case PulseModuleType::Conjunction:
				{
					// Update memory:
					memory[pulse.From] = pulse.High;

					// Send low pulse, if all memory values are high, else high pulse
					bool allHigh = std::all_of(memory.begin(), memory.end(), [](const auto& mem) { return mem.second; });
					for (const auto& dest : Destinations)
						pulsesSent.emplace_back(Name, dest, !allHigh);
					break;
				}

				case PulseModuleType::Broadcaster:
				{
					// Send the same pulse it received to all destinations:
					for (const auto& dest : Destinations)
						pulsesSent.emplace_back(Name, dest, pulse.High);
					break;
				}
			}

			return pulsesSent;
		}
	};
}
