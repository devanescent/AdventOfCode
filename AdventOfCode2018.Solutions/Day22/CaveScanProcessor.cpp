#include "CaveScanProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2018::Day22
{
	std::vector<CaveScan> CaveScanProcessor::Process(std::vector<std::string> input)
	{
		std::vector<CaveScan> scan(1);

		std::istringstream issDepth(input[0]);
		std::istringstream issTarget(input[1]);

		std::string ignore;
		char comma;
		issDepth >> ignore >> scan[0].Depth;
		issTarget >> ignore >> scan[0].TargetX >> comma >> scan[0].TargetY;

		return scan;
	}
}
