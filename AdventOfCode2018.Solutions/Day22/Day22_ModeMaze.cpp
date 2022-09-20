#include "Day22_ModeMaze.h"
#include <sstream>

namespace AdventOfCode::Year2018::Day22
{
	ModeMaze::ModeMaze() : Day(22, "Mode Maze") {}

	uint64_t ModeMaze::GetResultOnPart1(std::vector<std::string> input)
	{
		size_t depth;
		size_t targetX;
		size_t targetY;

		// Input data format:
		// depth: ZZZ
		// target: XXX,YYY
		std::istringstream issDepth(input[0]);
		std::istringstream issTarget(input[1]);

		std::string ignore;
		char comma;
		issDepth >> ignore >> depth;
		issTarget >> ignore >> targetX >> comma >> targetY;
		
		CaveMap caveMap(targetX, targetY, depth);
		return caveMap.GetRiskLevel();
	}
}