#pragma once
#include "InputProcessor.h"
#include "PartNumber.h"

namespace AdventOfCode::Year2023::Day03
{
	class EngineSchematicsProcessor : public InputProcessorBase<PartNumber>
	{
	public:
		std::vector<PartNumber> Process(std::vector<std::string> input) override;
	};
}
