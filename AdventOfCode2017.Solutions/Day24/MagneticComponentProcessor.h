#pragma once
#include "InputProcessor.h"
#include "MagneticComponent.h"

namespace AdventOfCode::Year2017::Day24
{
	class MagneticComponentProcessor : public InputProcessorBase<MagneticComponent>
	{
	public:
		std::vector<MagneticComponent> Process(std::vector<std::string> input) override;
	};
}
