#pragma once
#include "InputProcessor.h"
#include "Cube.h"

namespace AdventOfCode::Year2022::Day18
{
	class CubeProcessor : public InputProcessorBase<Cube>
	{
	public:
		std::vector<Cube> Process(std::vector<std::string> input) override;
	};
}
