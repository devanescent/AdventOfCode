#pragma once
#include "InputProcessor.h"
#include "GameRecord.h"

namespace AdventOfCode::Year2023::Day02
{
	class CubeGameProcessor : public InputProcessorBase<GameRecord>
	{
	public:
		std::vector<GameRecord> Process(std::vector<std::string> input) override;
	};
}
