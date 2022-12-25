#pragma once
#include "InputProcessor.h"
#include "SNAFUNumber.h"

namespace AdventOfCode::Year2022::Day25
{
	class SNAFUProcessor : public InputProcessorBase<SNAFUNumber>
	{
	public:
		std::vector<SNAFUNumber> Process(std::vector<std::string> input) override;
	};
}
