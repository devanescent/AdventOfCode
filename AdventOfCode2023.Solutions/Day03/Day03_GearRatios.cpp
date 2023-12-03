#include "Day03_GearRatios.h"
#include <numeric>
#include <unordered_map>

namespace AdventOfCode::Year2023::Day03
{
	GearRatios::GearRatios() : DayT(3, "Gear Ratios") { }

	uint64_t GearRatios::ExecutePart1(std::vector<PartNumber> partNumbers)
	{
		return std::accumulate(partNumbers.begin(), partNumbers.end(), 0ull,
			[](uint64_t sum, const PartNumber& pn)
			{
				return sum + pn.Value;
			});
	}

	uint64_t GearRatios::ExecutePart2(std::vector<PartNumber> partNumbers)
	{
		uint64_t gearRatioSum = 0;

		// Find gears:
		std::unordered_map<Point<int>, std::vector<PartNumber>> gears;
		for (const PartNumber& pn : partNumbers)
		{
			if (pn.EnginePart == '*')
				gears[pn.Position].push_back(pn);
		}

		for (const auto& gear : gears)
		{
			// Only count if exactly two part numbers belong to this gear:
			if (gear.second.size() == 2)
			{
				uint64_t gearRatio = gear.second[0].Value * gear.second[1].Value;
				gearRatioSum += gearRatio;
			}
		}

		return gearRatioSum;
	}
}
