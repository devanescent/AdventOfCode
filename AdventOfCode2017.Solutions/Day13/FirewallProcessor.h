#pragma once
#include "InputProcessor.h"
#include "FirewallLayer.h"

namespace AdventOfCode::Year2017::Day13
{
	class FirewallProcessor : public InputProcessorBase<FirewallLayer>
	{
	public:
		std::vector<FirewallLayer> Process(std::vector<std::string> input) override;
	};
}
