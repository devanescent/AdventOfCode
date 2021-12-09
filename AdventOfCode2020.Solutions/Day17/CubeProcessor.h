#pragma once
#include "InputProcessor.h"
#include "CubeCoords.h"

namespace AdventOfCode::Year2020::Day17
{
	class CubeProcessor : public InputProcessorBase<CubeCoords>
	{
	public:
		std::vector<CubeCoords> Process(std::vector<std::string> input) override;
	};
}

