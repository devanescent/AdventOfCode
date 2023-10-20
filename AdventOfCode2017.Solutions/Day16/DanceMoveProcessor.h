#pragma once
#include "InputProcessor.h"
#include "DanceMove.h"
#include <memory>

namespace AdventOfCode::Year2017::Day16
{
	class DanceMoveProcessor : public InputProcessorBase<std::unique_ptr<DanceMove>>
	{
	public:
		std::vector<std::unique_ptr<DanceMove>> Process(std::vector<std::string> input) override;
	};
}
