#pragma once
#include "InputProcessor.h"
#include "HexCoords.h"

namespace AdventOfCode::Year2020::Day24
{
	class HexProcessor : public InputProcessorBase<HexCoords>
	{
	public:
		std::vector<HexCoords> Process(std::vector<std::string> input) override;

	private:
		HexCoords ParseDirections(const std::string& directions);
	};

}
