#pragma once
#include "InputProcessor.h"
#include "SectionAssignments.h"

namespace AdventOfCode::Year2022::Day04
{
	class SectionAssignmentsProcessor : public InputProcessorBase<SectionAssignments>
	{
	public:
		std::vector<SectionAssignments> Process(std::vector<std::string> input) override;
	};
}
