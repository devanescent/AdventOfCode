#include "Day03_SpiralMemory.h"
#include <cmath>

namespace AdventOfCode::Year2017::Day03
{
	SpiralMemory::SpiralMemory() : Day(3, "Spiral Memory") { }

	uint64_t SpiralMemory::GetResultOnPart1(std::vector<std::string> input)
	{
		uint64_t target = std::stoull(input[0]);

		// Full rings are squares of odd numbers: 
		// Ring 0: all values <=1
		// Ring 1: all values <= 3x3=9
		// Ring 2: all values <= 5x5=25
		// Ring 3: all values <= 7x7=49
		// ...

		if (target == 1)
			return 0;

		// Get the ring the target square is on:
		uint64_t root = static_cast<uint64_t>(std::sqrt(target - 1));
		uint64_t ring = root % 2 == 0 ? root / 2 : (root + 1) / 2;

		// Distance to center within a ring oscillates between (ring) and (ring*2)
		// First number on a ring starts one above the ring's bottom right corner
		// -> starting distance = (ring * 2) - 1
		
		return std::abs((int64_t)(((target + (ring * 2 - 1)) % (2 * ring)) - ring)) + ring;
	}

	uint64_t SpiralMemory::GetResultOnPart2(std::vector<std::string> input)
	{
		return uint64_t();
	}
}
