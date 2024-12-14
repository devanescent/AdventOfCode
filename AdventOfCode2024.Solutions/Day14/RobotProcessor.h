#pragma once
#include "InputProcessor.h"
#include "Robot.h"

namespace AdventOfCode::Year2024::Day14
{
	class RobotProcessor : public InputProcessorBase<Robot>
	{
	public:
		std::vector<Robot> Process(std::vector<std::string> input) override;
	};
}
