#pragma once
#include "InputProcessor.h"
#include "Nanobot.h"

namespace AdventOfCode::Year2018::Day23
{
	class NanobotProcessor : public InputProcessorBase<Nanobot>
	{
	public:
		std::vector<Nanobot> Process(std::vector<std::string> input) override;
	};
}