#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2017::Day04
{
	class PassphraseProcessor : public InputProcessorBase<std::vector<std::string>>
	{
	public:
		std::vector<std::vector<std::string>> Process(std::vector<std::string> input) override;
	};
}
