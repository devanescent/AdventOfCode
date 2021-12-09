#include "Day17_ConvayCubes.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2020::Day17
{
	ConvayCubes::ConvayCubes(int cycles) : DayT(17, "Convey Cubes"), 
		m_cycles(cycles)
	{}

	uint64_t ConvayCubes::ExecutePart1(std::vector<CubeCoords> activeCubes)
	{
		for (int i = 0; i < m_cycles; ++i)
		{
			// Count neighbors around active cubes:
			std::map<CubeCoords, std::pair<bool, int>> nextGeneration;

			for (const CubeCoords& cube : activeCubes)
			{
				for (int dx = -1; dx <= 1; ++dx)
				{
					for (int dy = -1; dy <= 1; ++dy)
					{
						for (int dz = -1; dz <= 1; ++dz)
						{
							auto pCube = nextGeneration.insert(std::make_pair(CubeCoords(cube.X + dx, cube.Y + dy, cube.Z + dz), std::make_pair(false, 0))).first;

							if (dx != 0 || dy != 0 || dz != 0)
							{
								// add neighbor and increase active neighbor count:
								++pCube->second.second;	
							}
							else
							{
								// set itself as active node:
								pCube->second.first = true;
							}
						}
					}
				}
			}

			// find all active cubes for next iteration:
			activeCubes.clear();

			for (const auto& cube : nextGeneration)
			{
				// If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active.
				if (cube.second.first && (cube.second.second == 2 || cube.second.second == 3))
				{
					activeCubes.push_back(cube.first);
				}
				// If a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active
				else if (!cube.second.first && cube.second.second == 3)
				{
					activeCubes.push_back(cube.first);
				}
				// Otherwise, the cube remains / becomes inactive
			}
		}

		return activeCubes.size();
	}
}

