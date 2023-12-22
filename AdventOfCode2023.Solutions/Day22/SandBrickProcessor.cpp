#include "SandBrickProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day22
{
	std::vector<SandBrick> SandBrickProcessor::Process(std::vector<std::string> input)
	{
		std::vector<SandBrick> sandBricks;

		int brickNo = 1;
		for (const auto& line : input)
		{
			SandBrick brick;
			brick.Num = brickNo++;

			std::istringstream iss(line);
			char ignore;

			iss >> brick.X1 >> ignore >> brick.Y1 >> ignore >> brick.Z1 >> ignore
				>> brick.X2 >> ignore >> brick.Y2 >> ignore >> brick.Z2;

			if (brick.X1 > brick.X2)
				std::swap(brick.X1, brick.X2);

			if (brick.Y1 > brick.Y2)
				std::swap(brick.Y1, brick.Y2);

			if (brick.Z1 > brick.Z2)
				std::swap(brick.Z1, brick.Z2);

			sandBricks.emplace_back(brick);
		}

		return sandBricks;
	}
}
