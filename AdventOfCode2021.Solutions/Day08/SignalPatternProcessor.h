#pragma once
#include "InputProcessor.h"
#include "SignalPatternObservation.h"

namespace AdventOfCode::Year2021::Day08
{
	class SignalPatternProcessor : public InputProcessorBase<SignalPatternObservation>
	{
	public:
		std::vector<SignalPatternObservation> Process(std::vector<std::string> input) override;
	};
}

