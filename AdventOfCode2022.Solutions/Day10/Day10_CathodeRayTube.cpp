#include "Day10_CathodeRayTube.h"
#include <iostream>
#include <functional>

namespace AdventOfCode::Year2022::Day10
{
	CathodeRayTube::CathodeRayTube() : DayT(10, "Cathode Ray Tube") { }

	void ExecuteInstructions(const std::vector<Instruction>& instructions, std::function<void(const CPU&)> f)
	{
		CPU cpu{ 0, 1 };

		// Start executing first instruction:
		auto nextInstruction = instructions.begin();
		int remainingCycles = nextInstruction->GetCycles();

		while (nextInstruction != instructions.end())
		{
			++cpu.Cycle;

			// Has the current instruction finished?
			if (remainingCycles == 0)
			{
				nextInstruction->ExecuteOnCpu(cpu);

				++nextInstruction;
				if (nextInstruction != instructions.end())
					remainingCycles = nextInstruction->GetCycles();
			}

			--remainingCycles;

			// Execute during the current cycle:
			f(cpu);
		}
	}


	uint64_t CathodeRayTube::ExecutePart1(std::vector<Instruction> instructions)
	{
		int signalStrenthSum = 0;

		ExecuteInstructions(instructions,
			[&signalStrenthSum](const CPU& cpu)
			{
				// Measure signal strengths during the following cycles:
				switch (cpu.Cycle)
				{
					case 20: case 60: case 100: case 140: case 180: case 220:
						signalStrenthSum += cpu.GetSignalStrength();
						break;
				}
			}
		);

		return signalStrenthSum;
	}

	uint64_t CathodeRayTube::ExecutePart2(std::vector<Instruction> instructions)
	{
		int cpuPos = 0;

		ExecuteInstructions(instructions,
			[&cpuPos](const CPU& cpu)
			{
				// Drawing pixels:
				if (cpuPos == 40)
				{
					std::cout << "\n";
					cpuPos = 0;
				}

				std::cout << ((cpuPos >= cpu.Register - 1 && cpuPos <= cpu.Register + 1) ? "#" : " ");
				++cpuPos;
			}
		);

		return 0ull;
	}
}
