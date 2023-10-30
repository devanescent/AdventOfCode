#include "Day17_PyroclasticFlow.h"
#include "Point.h"
#include "Rock.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day17
{
	PyroclasticFlow::PyroclasticFlow() : Day(17, "Pyroclastic Flow") { }

	uint64_t PyroclasticFlow::ExecutePart1(std::vector<std::string> jets)
	{
		std::string jetPattern = jets[0];
		auto currentJet = jetPattern.begin();

		// Simulate 2022 rocks:
		std::unordered_set<Point<int>> rockStructure;
		int rockShape = 0;

		// Maximum height of each column:
		std::vector<int> maxHeights(7, 0);

		for (int rockNo = 1; rockNo <= 2022; ++rockNo)
		{
			// Current maximum height of the rock structure in the chamber:
			int rockTop = *std::max_element(maxHeights.begin(), maxHeights.end());

			// Rocks appear with three levels of empty space towards the top of the rock:
			Rock rock(static_cast<RockShape>(rockShape), rockTop + 4);

			// Move the rock:
			do
			{
				// Apply jet:
				if (currentJet == jetPattern.end())
					currentJet = jetPattern.begin();

				if (*currentJet == '>')
					rock.MoveRight(rockStructure);
				else if (*currentJet == '<')
					rock.MoveLeft(rockStructure);

				++currentJet;

			} while (rock.MoveDown(rockStructure));

			// Update heights:
			for (const Point<int>& rock : rockStructure)
				maxHeights[rock.X] = std::max(maxHeights[rock.X], rock.Y);

			rockShape = (rockShape + 1) % 5;
		}

		return *std::max_element(maxHeights.begin(), maxHeights.end());
	}

	uint64_t PyroclasticFlow::ExecutePart2(std::vector<std::string> jets)
	{
		return uint64_t();
	}
}
