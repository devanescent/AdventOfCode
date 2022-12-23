#include "Day23_UnstableDiffusion.h"
#include "Grove.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day23
{
	UnstableDiffusion::UnstableDiffusion() : DayT(23, "Unstable Diffusion") { }

	uint64_t UnstableDiffusion::ExecutePart1(std::vector<Elf> elves)
	{
		Grove grove;

		// Move elves for 10 rounds:
		for (int round = 0; round < 10; ++round)
			grove.MoveElves(elves);

		// Get bounding box size:
		auto xMinMax = std::minmax_element(elves.begin(), elves.end(), [](const Elf& elf1, const Elf& elf2) { return elf1.Pos.X < elf2.Pos.X; });
		auto yMinMax = std::minmax_element(elves.begin(), elves.end(), [](const Elf& elf1, const Elf& elf2) { return elf1.Pos.Y < elf2.Pos.Y; });
		
		int xMin = xMinMax.first->Pos.X;
		int xMax = xMinMax.second->Pos.X;
		int yMin = yMinMax.first->Pos.Y;
		int yMax = yMinMax.second->Pos.Y;

		// Return number of empty ground tiles:
		return (xMax - xMin + 1) * (yMax - yMin + 1) - elves.size();
	}

	uint64_t UnstableDiffusion::ExecutePart2(std::vector<Elf> elves)
	{
		Grove grove;

		// Move elves until the settle:
		int round = 1;
		while (grove.MoveElves(elves))
		{
			++round;
		}
			
		return round;
	}
}
