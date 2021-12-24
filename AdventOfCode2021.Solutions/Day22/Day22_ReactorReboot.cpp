#include "Day22_ReactorReboot.h"
#include <array>
#include <algorithm>

namespace AdventOfCode::Year2021::Day22
{
	ReactorReboot::ReactorReboot() : DayT(22, "Reactor Reboot") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t ReactorReboot::ExecutePart1(std::vector<RebootStep> steps)
	{
		std::vector<std::vector<std::vector<bool>>> core(101, std::vector<std::vector<bool>>(101, std::vector<bool>(101, false)));

		for (const auto& step : steps)
		{
			// Only consider areas inside +/-50 in each direction:
			for (int z = std::max(step.FromZ, -50); z <= std::min(step.ToZ, 50); ++z)
			{
				for (int y = std::max(step.FromY, -50); y <= std::min(step.ToY, 50); ++y)
				{
					for (int x = std::max(step.FromX, -50); x <= std::min(step.ToX, 50); ++x)
					{
						// Mapping Cube-Coord => Core-Array:
						// -------------------------------------
						// Indices -50..-1 => 0..49
						// Index         0 => 50
						// Indices +1..+50 => 51..100
						core[z+50][y+50][x+50] = step.NewState;
					}
				}
			}
		}

		// Count all cells that are 'on':
		uint64_t onCubes = 0;

		for (const auto& layer : core) // z-Coord
		{
			for (const auto& row : layer) // y-Coord
			{
				onCubes += std::count(row.begin(), row.end(), true);
			}
		}

		return onCubes;
	}
}

