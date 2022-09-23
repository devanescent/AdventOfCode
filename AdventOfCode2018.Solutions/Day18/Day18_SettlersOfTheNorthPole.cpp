#include "Day18_SettlersOfTheNorthPole.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day18
{
	SettlersOfTheNorthPole::SettlersOfTheNorthPole() : Day(18, "Settlers Of The North Pole") {}


	uint64_t SettlersOfTheNorthPole::GetResultOnPart1(std::vector<std::string> ground)
	{
		for (int t = 0; t < 10; ++t)
			ground = TransformGround(ground);

		return GetResourceValue(ground);
	}

	uint64_t SettlersOfTheNorthPole::GetResultOnPart2(std::vector<std::string> ground)
	{
		// Let run long enough that the ground transforms in a cyclic pattern:
		for (int t = 0; t < 1000; ++t)
			ground = TransformGround(ground);

		// Find the cycle period:
		std::vector<std::vector<std::string>> prevPatterns;

		// Compare first pattern to current pattern to find out when the pattern repeats:
		while (prevPatterns.empty() || prevPatterns[0] != ground)
		{
			prevPatterns.push_back(ground);
			ground = TransformGround(ground);
		}

		// Number of patterns after which it repeats:
		size_t cycle = prevPatterns.size();
		
		// Find pattern after 1'000'000'000 (-1000 for initial transformations that were not looked at):
		return GetResourceValue(prevPatterns[(1'000'000'000 - 1000) % cycle]);
	}

	std::vector<std::string> SettlersOfTheNorthPole::TransformGround(const std::vector<std::string>& ground)
	{
		std::vector<std::string> transformedGround(ground); // copy original ground

		size_t groundWidth = ground[0].length();
		size_t groundHeight = ground.size();

		for (size_t y = 0; y < groundHeight; ++y)
		{
			for (size_t x = 0; x < groundWidth; ++x)
			{
				// An open acre will become filled with trees if three or more adjacent acres contained trees.
				// Otherwise, nothing happens.
				if (AcreType::OpenGround == static_cast<AcreType>(ground[y][x]) && GetNumberOfAdjacentAcresByType(ground, x, y, AcreType::Trees) >= 3)
					transformedGround[y][x] = static_cast<char>(AcreType::Trees);

				// An acre filled with trees will become a lumberyard if three or more adjacent acres were lumberyards.
				// Otherwise, nothing happens.
				else if (AcreType::Trees == static_cast<AcreType>(ground[y][x]) && GetNumberOfAdjacentAcresByType(ground, x, y, AcreType::Lumberyard) >= 3)
					transformedGround[y][x] = static_cast<char>(AcreType::Lumberyard);

				// An acre containing a lumberyard will remain a lumberyard if it was adjacent to at least one other lumberyard
				// and at least one acre containing trees. Otherwise, it becomes open.
				else if (AcreType::Lumberyard == static_cast<AcreType>(ground[y][x]))
				{
					if (GetNumberOfAdjacentAcresByType(ground, x, y, AcreType::Lumberyard) == 0 || GetNumberOfAdjacentAcresByType(ground, x, y, AcreType::Trees) == 0)
						transformedGround[y][x] = static_cast<char>(AcreType::OpenGround);
				}
			}
		}

		return transformedGround;
	}

	int SettlersOfTheNorthPole::GetNumberOfAdjacentAcresByType(const std::vector<std::string>& ground, size_t x, size_t y, AcreType acreType)
	{
		size_t groundWidth = ground[0].length();
		size_t groundHeight = ground.size();

		int acreCount = 0;

		if (y > 0) acreCount += (acreType == static_cast<AcreType>(ground[y - 1][x])); // top
		if (y < groundHeight - 1) acreCount += (acreType == static_cast<AcreType>(ground[y + 1][x])); // bottom

		if (x > 0)
		{
			acreCount += (acreType == static_cast<AcreType>(ground[y][x - 1])); // left
			if (y > 0) acreCount += (acreType == static_cast<AcreType>(ground[y - 1][x - 1])); // top-left
			if (y < groundHeight - 1) acreCount += (acreType == static_cast<AcreType>(ground[y + 1][x - 1])); // bottom-left
		}

		if (x < groundWidth - 1)
		{
			acreCount += (acreType == static_cast<AcreType>(ground[y][x + 1])); // right
			if (y > 0) acreCount += (acreType == static_cast<AcreType>(ground[y - 1][x + 1])); // top-right
			if (y < groundHeight - 1) acreCount += (acreType == static_cast<AcreType>(ground[y + 1][x + 1])); // bottom-right
		}

		return acreCount;
	}

	uint64_t SettlersOfTheNorthPole::GetResourceValue(const std::vector<std::string>& ground)
	{
		uint64_t numberOfWoodenAcres = 0, numberOfLumberyards = 0;

		size_t groundWidth = ground[0].length();
		size_t groundHeight = ground.size();

		for (size_t y = 0; y < groundHeight; ++y)
		{
			for (size_t x = 0; x < groundWidth; ++x)
			{
				switch (static_cast<AcreType>(ground[y][x]))
				{
					case AcreType::Lumberyard: ++numberOfLumberyards; break;
					case AcreType::Trees: ++numberOfWoodenAcres; break;
				}
			}
		}

		return numberOfWoodenAcres * numberOfLumberyards;
	}
}