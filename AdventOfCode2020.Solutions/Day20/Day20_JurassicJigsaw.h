#pragma once
#include "DayT.h"
#include "Tile.h"
#include "TileProcessor.h"

namespace AdventOfCode::Year2020::Day20
{
	class JurassicJigsaw : public DayT<TileProcessor>
	{
	public:
		JurassicJigsaw();

	protected:
		uint64_t ExecutePart1(std::vector<Tile> tiles) override;
	};
}
