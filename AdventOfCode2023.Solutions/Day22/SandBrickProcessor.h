#pragma once
#include "InputProcessor.h"
#include "SandBrick.h"

namespace AdventOfCode::Year2023::Day22
{
	class SandBrickProcessor : public InputProcessorBase<SandBrick>
	{
	public:
		std::vector<SandBrick> Process(std::vector<std::string> input) override;
	};
}
