#pragma once
#include "InputProcessorWithContext.h"
#include "MoveInstruction.h"
#include "JungleMap.h"

namespace AdventOfCode::Year2022::Day22
{
	class MonkeyMapProcessor : public InputProcessorWithContextBase<MoveInstruction, JungleMap>
	{
	public:
		std::pair<std::vector<MoveInstruction>, JungleMap> Process(std::vector<std::string> input) override;
	};
}
