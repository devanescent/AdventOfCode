#pragma once
#include "InputProcessor.h"
#include "Calibration.h"

namespace AdventOfCode::Year2024::Day07
{
	class BridgeCalibrationsProcessor : public InputProcessorBase<Calibration>
	{
	public:
		std::vector<Calibration> Process(std::vector<std::string> input) override;
	};
}
