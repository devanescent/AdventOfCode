#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2018::Day22
{
	struct CaveScan
	{
		int TargetX;
		int TargetY;
		int Depth;
	};

	class CaveScanProcessor : public InputProcessorBase<CaveScan>
	{
	public:
		std::vector<CaveScan> Process(std::vector<std::string> input) override;
	};
}