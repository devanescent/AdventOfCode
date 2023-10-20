#pragma once
#include "InputProcessor.h"
#include "Pipe.h"

namespace AdventOfCode::Year2017::Day12
{
	class PipeProcessor : public InputProcessorBase<Pipe>
	{
	public:
		std::vector<Pipe> Process(std::vector<std::string> input) override;
	};
}
