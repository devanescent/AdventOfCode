#include "Day14_RestroomRedoubt.h"
#include <algorithm>
#include <iostream>

namespace AdventOfCode::Year2024::Day14
{
	RestroomRedoubt::RestroomRedoubt() : DayT(14, "Restroom Redoubt") { }

	uint64_t RestroomRedoubt::ExecutePart1(std::vector<Robot> robots)
	{
		// Convert negative velocities to the a positive velocity to handle teleporting easier:
		for (Robot& robot : robots)
			robot.ConvertNegativeVelocity(_areaWidth, _areaHeight);

		// Simulate robot movement for 100 seconds:
		for (int sec = 0; sec < 100; ++sec)
		{
			for (Robot& robot : robots)
				robot.UpdatePostion(_areaWidth, _areaHeight);
		}

		// Calculate safety factor
		uint64_t topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
		for (Robot& robot : robots)
		{
			if (robot.Position.X < _areaWidth / 2 && robot.Position.Y < _areaHeight / 2)
			{
				// Top left quadrant
				++topLeft;
			}
			if (robot.Position.X > _areaWidth / 2 && robot.Position.Y < _areaHeight / 2)
			{
				// Top right quadrant
				++topRight;
			}
			else if (robot.Position.X < _areaWidth / 2 && robot.Position.Y > _areaHeight / 2)
			{
				// Bottom left quadrant
				++bottomLeft;
			}
			else if (robot.Position.X > _areaWidth / 2 && robot.Position.Y > _areaHeight / 2)
			{
				// Bottom right quadrant
				++bottomRight;
			}
		}

		return topLeft * topRight * bottomLeft * bottomRight;
	}

	uint64_t RestroomRedoubt::ExecutePart2(std::vector<Robot> robots)
	{
		// Convert negative velocities to the a positive velocity to handle teleporting easier:
		for (Robot& robot : robots)
			robot.ConvertNegativeVelocity(_areaWidth, _areaHeight);

		// Simulate robot movement while counting seconds:
		uint64_t secondsUntilChristmasTree = 0;
		while (++secondsUntilChristmasTree)
		{
			for (Robot& robot : robots)
				robot.UpdatePostion(_areaWidth, _areaHeight);

			// Count number of robots with another robot directly next to them:
			auto robotsWithNeighbors = std::count_if(robots.begin(), robots.end(),
				[&robots](const Robot& r1)
				{
					// For each robot find a robot adjacent to it:
					return std::find_if(robots.begin(), robots.end(),
						[&r1](const Robot& r2)
						{
							return r1.Position != r2.Position &&
								std::abs(r1.Position.X - r2.Position.X) <= 1 && 
								std::abs(r1.Position.Y - r2.Position.Y) <= 1;
						}) != robots.end();
				});
			
			// Assume 60% of robots must have a neighbor to form the christmas tree image:
			if (robotsWithNeighbors > (robots.size() * 0.6))
			{
				// Draw robots on screen:
				std::vector<std::string> area(_areaHeight, std::string(_areaWidth, ' '));

				for (Robot& robot : robots)
					area[robot.Position.Y][robot.Position.X] = '#';

				for (std::string& line : area)
					std::cout << line << "\n";

				break;
			}
			else if (secondsUntilChristmasTree % 500 == 0)
			{
				// Otherwise give an update about seconds that have passed every 500 seconds:
				std::cout << " " << secondsUntilChristmasTree;
			}
		}

		return secondsUntilChristmasTree;
	}
}
