#include "ByteProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2024::Day18
{
	std::vector<Point<int>> ByteProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Point<int>> bytes;

		for (const auto& line : input)
		{
			std::istringstream iss(line);

			Point<int> p;
			char comma;

			iss >> p.X >> comma >> p.Y;
			bytes.emplace_back(p);
		}

		return bytes;
	}
}
