#pragma once
#include "InputProcessor.h"
#include "Scanner.h"

namespace AdventOfCode::Year2021::Day19
{
	class ScannerProcessor : public InputProcessorBase<Scanner>
	{
	public:
		std::vector<Scanner> Process(std::vector<std::string> input) override;
	};
}
