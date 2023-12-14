#pragma once
#include "InputProcessorWithContext.h"
#include "Rock.h"
#include "Platform.h"

namespace AdventOfCode::Year2023::Day14
{
	class PlatformRocksProcessor : public InputProcessorWithContextBase<Rock, Platform>
	{
	public:
		std::pair<std::vector<Rock>, Platform> Process(std::vector<std::string> input) override;
	};
}
