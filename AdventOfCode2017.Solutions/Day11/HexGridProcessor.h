#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2017::Day11
{
	enum class HexDirection
	{
		North,
		NorthEast,
		NorthWest,
		South,
		SouthEast,
		SouthWest,
	};

	class HexGridProcessor : public InputProcessorBase<HexDirection>
	{
	public:
		std::vector<HexDirection> Process(std::vector<std::string> input) override;
	};
}
