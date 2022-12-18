#include "CubeProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2022::Day18
{
	std::vector<Cube> CubeProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Cube> cubes;
		cubes.reserve(input.size());

		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			
			int x, y, z;
			char comma;
			iss >> x >> comma >> y >> comma >> z;
			cubes.emplace_back(x, y, z);
		}

		return cubes;
	}
}
