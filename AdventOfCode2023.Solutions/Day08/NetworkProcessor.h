#pragma once
#include "InputProcessorWithContext.h"
#include "NetworkNode.h"

namespace AdventOfCode::Year2023::Day08
{
	class NetworkProcessor : public InputProcessorWithContextBase<NetworkNode, std::vector<Direction>>
	{
	public:
		std::pair<std::vector<NetworkNode>, std::vector<Direction>> Process(std::vector<std::string> input) override;
	};
}
