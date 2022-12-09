#pragma once
#include "InputProcessor.h"
#include "RopeMovement.h"

namespace AdventOfCode::Year2022::Day09
{
	class RopeMovementProcessor : public InputProcessorBase<RopeMovement>
	{
	public:
		std::vector<RopeMovement> Process(std::vector<std::string> input) override;
	};
}
