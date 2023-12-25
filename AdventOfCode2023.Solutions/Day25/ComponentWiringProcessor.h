#pragma once
#include "InputProcessor.h"
#include "Wiring.h"

namespace AdventOfCode::Year2023::Day25
{
	class ComponentWiringProcessor : public InputProcessorBase<Wiring>
	{
	public:
		std::vector<Wiring> Process(std::vector<std::string> input) override;
	};
}
