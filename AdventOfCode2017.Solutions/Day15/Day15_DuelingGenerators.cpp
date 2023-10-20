#include "Day15_DuelingGenerators.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day15
{
	DuelingGenerators::DuelingGenerators() : Day(15, "Dueling Generators") { }

	uint64_t DuelingGenerators::GetResultOnPart1(std::vector<std::string> input)
	{
		// Initial values for the generators:
		uint64_t genA, genB;
		std::string discard;
	
		std::istringstream issA(input[0]);
		issA >> discard >> discard >> discard >> discard >> genA;

		std::istringstream issB(input[1]);
		issB >> discard >> discard >> discard >> discard >> genB;

		// Generate values and compare:
		uint64_t matches = 0;
		for (int i = 0; i < 40'000'000; ++i)
		{
			genA = (genA * 16807) % 2147483647;
			genB = (genB * 48271) % 2147483647;

			matches += (genA & 0xFFFF) == (genB & 0xFFFF) ? 1 : 0;
		}

		return matches;
	}

	uint64_t DuelingGenerators::GetResultOnPart2(std::vector<std::string> input)
	{
		// Initial values for the generators:
		uint64_t genA, genB;
		std::string discard;

		std::istringstream issA(input[0]);
		issA >> discard >> discard >> discard >> discard >> genA;

		std::istringstream issB(input[1]);
		issB >> discard >> discard >> discard >> discard >> genB;

		// Generate values and compare:
		uint64_t matches = 0;
		for (int i = 0; i < 5'000'000; ++i)
		{
			do
			{
				genA = (genA * 16807) % 2147483647;
			} while (genA % 4 != 0);
			
			do
			{
				genB = (genB * 48271) % 2147483647;
			} while (genB % 8 != 0);

			matches += (genA & 0xFFFF) == (genB & 0xFFFF) ? 1 : 0;
		}

		return matches;
	}
}
