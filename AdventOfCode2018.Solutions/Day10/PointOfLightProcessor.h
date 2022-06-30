#pragma once
#include "InputProcessor.h"
#include "PointOfLight.h"

namespace AdventOfCode::Year2018::Day10
{
	class PointOfLightProcessor : public InputProcessorBase<PointOfLight>
	{
	public:
		std::vector<PointOfLight> Process(std::vector<std::string> input) override;
	};
}