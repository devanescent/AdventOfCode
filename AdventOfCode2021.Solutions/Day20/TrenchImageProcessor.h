#pragma once
#include "InputProcessorWithContext.h"

namespace AdventOfCode::Year2021::Day20
{
	class TrenchImageProcessor : public InputProcessorWithContextBase<std::string, std::string>
	{
	public:
		virtual std::pair<std::vector<std::string>, std::string> Process(std::vector<std::string> input) override;
	};
}