#pragma once
#include "InputProcessor.h"
#include "Point.h"

namespace AdventOfCode::Year2024::Day18
{
	class ByteProcessor : public InputProcessorBase<Point<int>>
	{
	public:
		std::vector<Point<int>> Process(std::vector<std::string> input) override;
	};
}
