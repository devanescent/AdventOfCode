#pragma once
#include "Range.h"

namespace AdventOfCode::Year2023::Day05
{
	enum class MappingType
	{
		Undefined,
		Seed,
		Soil,
		Fertilizer,
		Water,
		Light,
		Temperature,
		Humidity,
		Location,
		MappingEnd
	};

	class SeedMapping
	{
	public:
		MappingType SourceType;
		Range<uint64_t> SourceRange;
		MappingType DestinationType;
		Range<uint64_t> DestinationRange;

		bool ApplyTo(uint64_t& seed) const
		{
			if (SourceRange.ContainsValue(seed))
			{
				seed = DestinationRange.Start + (seed - SourceRange.Start);
				return true;
			}
			else
				return false;
		}
	};
}
