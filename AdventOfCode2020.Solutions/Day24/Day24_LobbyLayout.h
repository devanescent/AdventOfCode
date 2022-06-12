#pragma once
#include "DayT.h"
#include "HexCoords.h"
#include "HexProcessor.h"

namespace AdventOfCode::Year2020::Day24
{
	class LobbyLayout : public DayT<HexProcessor>
	{
	public:
		LobbyLayout();

	protected:
		uint64_t ExecutePart1(std::vector<HexCoords> coordsList) override;
	};
}