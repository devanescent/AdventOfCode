#include "Day18_BoilingBoulders.h"
#include <algorithm>
#include <array>
#include <queue>
#include <set>

namespace AdventOfCode::Year2022::Day18
{
	BoilingBoulders::BoilingBoulders() : DayT(18, "Boiling Boulders") { }

	// Represent the side of a cube with its center point:
	std::array<Cube, 6> GetCubeSides(const Cube& cube)
	{
		std::array<Cube, 6> sides{};

		// Resize each cube by factor 2, so the center coordinates are integer values:
		Cube cubeX2{ cube.X * 2, cube.Y * 2, cube.Z * 2 };

		// Left center:
		sides[0] = { cubeX2.X + 1, cubeX2.Y, cubeX2.Z + 1 };

		// Right center:
		sides[1] = { cubeX2.X + 1, cubeX2.Y + 2, cubeX2.Z + 1 };

		// Back center:
		sides[2] = { cubeX2.X, cubeX2.Y + 1, cubeX2.Z + 1 };

		// Front center:
		sides[3] = { cubeX2.X + 2, cubeX2.Y + 1, cubeX2.Z + 1 };

		// Bottom center:
		sides[4] = { cubeX2.X + 1, cubeX2.Y + 1, cubeX2.Z };

		// Top center:
		sides[5] = { cubeX2.X + 1, cubeX2.Y + 1, cubeX2.Z + 2 };

		return sides;
	}

	uint64_t BoilingBoulders::ExecutePart1(std::vector<Cube> cubes)
	{
		// Collect all surface center points from all cubes:
		std::multiset<Cube> allSides;
		for (const auto& cube : cubes)
		{
			auto sides = GetCubeSides(cube);
			allSides.insert(sides.begin(), sides.end());
		}

		// Surface area = unique center points:
		return std::count_if(allSides.begin(), allSides.end(),
			[&allSides](const Cube& side) { return allSides.count(side) == 1; }
		);
	}

	uint64_t BoilingBoulders::ExecutePart2(std::vector<Cube> cubes)
	{
		// Bounding box:
		auto xBounds = std::minmax_element(cubes.begin(), cubes.end(), [](const Cube& c1, const Cube& c2) { return c1.X < c2.X; });
		auto yBounds = std::minmax_element(cubes.begin(), cubes.end(), [](const Cube& c1, const Cube& c2) { return c1.Y < c2.Y; });
		auto zBounds = std::minmax_element(cubes.begin(), cubes.end(), [](const Cube& c1, const Cube& c2) { return c1.Z < c2.Z; });

		int xMin = xBounds.first->X - 1;
		int xMax = xBounds.second->X + 1;
		int yMin = yBounds.first->Y - 1;
		int yMax = yBounds.second->Y + 1;
		int zMin = zBounds.first->Z - 1;
		int zMax = zBounds.second->Z + 1;

		// Use flood-fill to find space reachable by water within a box around the lava droplet
		std::set<Cube> waterBox;
		std::queue<Cube> q;
		q.push(Cube{ xMin, yMin, zMin });

		auto addCube = [&](Cube c)
		{
			// Check bounding box:
			if (c.X < xMin || c.X > xMax || c.Y < yMin || c.Y > yMax || c.Z < zMin || c.Z > zMax)
				return;
			// If cube does not belong to the lava droplet and has not been inserted:
			else if (std::find(cubes.begin(), cubes.end(), c) == cubes.end() && waterBox.insert(c).second)
				q.push(c);
		};

		while (!q.empty())
		{
			Cube c = q.front();
			q.pop();
			
			// Check all 6 adjacent cubes:
			addCube({ c.X, c.Y - 1, c.Z }); // left
			addCube({ c.X, c.Y + 1, c.Z }); // right
			addCube({ c.X + 1, c.Y, c.Z }); // front
			addCube({ c.X - 1, c.Y, c.Z }); // back
			addCube({ c.X, c.Y, c.Z + 1 }); // top
			addCube({ c.X, c.Y, c.Z - 1 }); // bottom
		}

		// Get surface area of the water box cubes with part 1:
		// This includes the outer surface area of the water box (which is known) and the inner surface, 
		// which is actually the outer surface of the lava droplet:
		auto waterBoxSurface = ExecutePart1({ waterBox.begin(), waterBox.end() });

		// Subtract outer surface of water box:
		int xLen = xMax - xMin + 1;
		int yLen = yMax - yMin + 1;
		int zLen = zMax - zMin + 1;

		return waterBoxSurface - (xLen * yLen * 2) - (xLen * zLen * 2) - (yLen * zLen * 2);
	}
}
