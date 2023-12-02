#pragma once
#include <algorithm>
#include <vector>

namespace AdventOfCode::Year2023::Day02
{
	class CubeSet
	{
	public:
		int RedCubes;
		int BlueCubes;
		int GreenCubes;
	};

	class GameRecord
	{
	public:
		int GameNo;
		std::vector<CubeSet> CubeSets;
	};
}
