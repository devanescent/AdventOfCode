#pragma once
#include "InputProcessor.h"
#include "Sensor.h"

namespace AdventOfCode::Year2022::Day15
{
	class SensorProcessor : public InputProcessorBase<Sensor>
	{
	public:
		std::vector<Sensor> Process(std::vector<std::string> input) override;
	};
}
