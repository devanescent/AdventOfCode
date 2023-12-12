#pragma once
#include "InputProcessor.h"
#include "SpringReport.h"

namespace AdventOfCode::Year2023::Day12
{
	class SpringReportProcessor : public InputProcessorBase<SpringReport>
	{
	public:
		std::vector<SpringReport> Process(std::vector<std::string> input) override;
	};
}
