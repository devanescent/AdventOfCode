#pragma once
#include "DayT.h"
#include "RebootStepProcessor.h"

namespace AdventOfCode::Year2021::Day22
{
	class ReactorReboot : public DayT<RebootStepProcessor>
	{
	public:
		ReactorReboot();

	protected:
		uint64_t ExecutePart1(std::vector<RebootStep> steps) override;
	};
}