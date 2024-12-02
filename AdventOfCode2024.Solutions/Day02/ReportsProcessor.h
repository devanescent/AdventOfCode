#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2024::Day02
{
	using Report = std::vector<int>;

	class ReportsProcessor : public InputProcessorBase<Report>
	{
	public:
		std::vector<Report> Process(std::vector<std::string> input) override;
	};
}
