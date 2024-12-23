#pragma once
#include "InputProcessor.h"
#include "Connection.h"

namespace AdventOfCode::Year2024::Day23
{
	class ConnectionProcessor : public InputProcessorBase<Connection>
	{
	public:
		std::vector<Connection> Process(std::vector<std::string> input) override;
	};
}
