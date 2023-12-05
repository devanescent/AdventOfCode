#include "AlmanacProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day05
{
	std::pair<std::vector<SeedMapping>, std::vector<uint64_t>> AlmanacProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<SeedMapping>, std::vector<uint64_t>> almanac;
		std::vector<SeedMapping>& mappings = almanac.first;
		std::vector<uint64_t>& seeds = almanac.second;

		// First line: seeds
		std::istringstream iss(input[0]);
		std::string ignore;
		iss >> ignore; // ignore "seeds:" prefix

		uint64_t seed;
		while (iss >> seed)
			seeds.emplace_back(seed);

		MappingType mapFrom = MappingType::Undefined, mapTo = MappingType::Seed;

		for (auto lineIt = input.begin() + 1; lineIt != input.end(); ++lineIt)
		{
			if (lineIt->empty())
			{
				// next mapping types:
				mapFrom = static_cast<MappingType>(static_cast<int>(mapFrom) + 1);
				mapTo = static_cast<MappingType>(static_cast<int>(mapTo) + 1);
				++lineIt; // skip map name
			}
			else
			{
				uint64_t destinationRangeStart, sourceRangeStart, rangeLength;
				iss = std::istringstream(*lineIt);
				iss >> destinationRangeStart >> sourceRangeStart >> rangeLength;

				SeedMapping mapping
				{
					mapFrom,
					{ sourceRangeStart, sourceRangeStart + rangeLength - 1 },
					mapTo,
					{ destinationRangeStart, destinationRangeStart + rangeLength - 1 }
				};
				mappings.emplace_back(mapping);
			}
		}


		return almanac;
	}
}
