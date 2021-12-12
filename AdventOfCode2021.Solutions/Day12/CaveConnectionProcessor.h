#pragma once
#include "InputProcessor.h"
#include "CaveConnection.h"

namespace AdventOfCode::Year2021::Day12
{
	class CaveConnectionProcessor : public InputProcessorBase<CaveConnection>
	{
	public:
		virtual std::vector<CaveConnection> Process(std::vector<std::string> input) override;
	};

}