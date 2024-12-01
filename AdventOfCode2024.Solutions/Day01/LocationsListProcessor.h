#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2024::Day01
{
	using LocationList = std::vector<int>;

	class LocationsListProcessor : public InputProcessorBase<LocationList>
	{
	public:
		std::vector<LocationList> Process(std::vector<std::string> input) override;
	};
}
