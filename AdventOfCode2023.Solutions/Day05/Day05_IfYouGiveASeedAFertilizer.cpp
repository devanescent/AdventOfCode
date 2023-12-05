#include "Day05_IfYouGiveASeedAFertilizer.h"
#include <list>
#include <map>

namespace AdventOfCode::Year2023::Day05
{
	IfYouGiveASeedAFertilizer::IfYouGiveASeedAFertilizer() : DayTC(5, "If You Give A Seed A Fertilizer") { }

	std::map<MappingType, std::vector<SeedMapping>> GroupMappings(const std::vector<SeedMapping>& seedMappings)
	{
		std::map<MappingType, std::vector<SeedMapping>> mappingFromType;
		for (const auto& mapping : seedMappings)
		{
			mappingFromType[mapping.SourceType].push_back(mapping);
		}
		return mappingFromType;
	}

	MappingType GetNextType(MappingType currentType)
	{
		return static_cast<MappingType>(static_cast<int>(currentType) + 1);
	}

	uint64_t IfYouGiveASeedAFertilizer::ExecutePart1(std::vector<SeedMapping> seedMappings, std::vector<uint64_t> seeds)
	{
		auto mappingFromType = GroupMappings(seedMappings);

		uint64_t lowestLocationNumber = UINT64_MAX;
		for (uint64_t seed : seeds)
		{
			MappingType currentSourceType = MappingType::Seed;
			while (currentSourceType != MappingType::Location)
			{
				for (const auto& mapping : mappingFromType[currentSourceType])
				{
					// First mapping that applies to the current value;
					// if no mapping applies, value will stay the same
					if (mapping.ApplyTo(seed))
						break;
				}
				currentSourceType = GetNextType(currentSourceType);
			}

			// After mapping all the way to location, remember lowest location number:
			lowestLocationNumber = std::min(lowestLocationNumber, seed);
		}
		return lowestLocationNumber;
	}

	uint64_t IfYouGiveASeedAFertilizer::ExecutePart2(std::vector<SeedMapping> seedMappings, std::vector<uint64_t> seeds)
	{
		auto mappingFromType = GroupMappings(seedMappings);

		// Convert ranges from seeds to locations:
		// -> use list to add unmapped (partial) ranges during mapping
		std::list<Range<uint64_t>> currentRanges;

		// Construct initial ranges from seeds:
		for (auto seedPairIt = seeds.begin(); seedPairIt != seeds.end(); seedPairIt += 2)
		{
			uint64_t seedRangeStart = *seedPairIt;
			uint64_t seedRangeLength = *(seedPairIt + 1);
			currentRanges.emplace_back(seedRangeStart, seedRangeStart + seedRangeLength - 1);
		}

		MappingType currentRangeType = MappingType::Seed;
		do
		{
			// Result after mapping all ranges from the current type to the next:
			std::list<Range<uint64_t>> mappedRanges;
			for (auto rangeIt = currentRanges.begin(); rangeIt != currentRanges.end(); ++rangeIt)
			{
				// Find mapping that applies:
				bool foundMapping = false;
				for (const SeedMapping& fromTypeMapping : mappingFromType[currentRangeType])
				{
					if (rangeIt->OverlapsWith(fromTypeMapping.SourceRange))
					{
						foundMapping = true;

						// Extract the partial range the mapping actually applies to:
						auto actualMappedRange = rangeIt->Intersect(fromTypeMapping.SourceRange);

						// Map this part of the range and add it to the ranges for the next iteration (i.e. the next type):
						mappedRanges.emplace_back(actualMappedRange.Shift(fromTypeMapping.DestinationRange.Start - fromTypeMapping.SourceRange.Start));

						// Add remaining (partial) ranges to the list of current mappings,
						// so they can be processed again:
						if (actualMappedRange.Start > rangeIt->Start)
						{
							// Left over area before the mapped range:
							currentRanges.emplace_back(rangeIt->Start, actualMappedRange.Start - 1);
						}
						if (actualMappedRange.End < rangeIt->End)
						{
							// Left over area after the mapped range:
							currentRanges.emplace_back(actualMappedRange.End + 1, rangeIt->End);
						}
					}
				}

				if (!foundMapping)
				{
					// If no mapping was applicable: copy the full range directly over to the next iteration:
					mappedRanges.push_back(*rangeIt);
				}
			}

			// All ranges mapped to the next type: start over until all ranges have been mapped to type 'location'
			currentRangeType = GetNextType(currentRangeType);
			currentRanges = mappedRanges;

		} while (currentRangeType != MappingType::MappingEnd);

		// Find lowest value in all mapped ranges:
		auto lowestLocationRange = std::min_element(currentRanges.begin(), currentRanges.end(),
			[](const Range<uint64_t>& r1, const Range<uint64_t>& r2)
			{
				return r1.Start < r2.Start;
			});

		return lowestLocationRange->Start;
	}
}
