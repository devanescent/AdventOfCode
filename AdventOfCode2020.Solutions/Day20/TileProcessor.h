#pragma once
#include "InputProcessor.h"
#include "Tile.h"

namespace AdventOfCode::Year2020::Day20
{
	class TileProcessor : public InputProcessorBase<Tile>
	{
	public:
		std::vector<Tile> Process(std::vector<std::string> input) override;
	};
}


