#pragma once
#include "InputProcessor.h"
#include "HydroVentLine.h"

namespace AdventOfCode::Year2021::Day05
{
	class HydroVentProcessor : public InputProcessorBase<HydroVentLine>
	{
	public:
		virtual std::vector<HydroVentLine> Process(std::vector<std::string> input) override;
	};
}