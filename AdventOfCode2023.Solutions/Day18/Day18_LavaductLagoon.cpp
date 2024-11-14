#include "Day18_LavaductLagoon.h"
#include "Point.h"
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>

namespace AdventOfCode::Year2023::Day18
{
	LavaductLagoon::LavaductLagoon() : DayT(18, "Lavaduct Lagoon") { }

	uint64_t GetAreaSize(std::vector<DigPlan>& digPlans, bool extractValuesFromColor)
	{
		// +---+---+
		// | ##### |  ### = path through the trenches
		// +-#-+-#-+
		// | # | # |
		// +-#-+-#-+---+
		// | # | ##### |
		// +-#-+---+-#-+
		// | ######### |
		// +---+---+---+

		// Move through trench:
		std::vector<Point<int64_t>> trenchCorners;

		Point<int64_t> currentCorner{ 0, 0 };
		trenchCorners.push_back(currentCorner);

		for (auto& digPlan : digPlans)
		{
			if (extractValuesFromColor)
				digPlan.ExtractFromColor();

			currentCorner = currentCorner.MoveBy(digPlan.dx * digPlan.Steps, digPlan.dy * digPlan.Steps);
			trenchCorners.push_back(currentCorner);
		}

		// Move all point to positive coordinates:
		auto xMin = std::min_element(trenchCorners.begin(), trenchCorners.end(),
			[](const Point<int64_t>& p1, const Point<int64_t>& p2) { return p1.X < p2.X; }
		)->X;

		auto yMin = std::min_element(trenchCorners.begin(), trenchCorners.end(),
			[](const Point<int64_t>& p1, const Point<int64_t>& p2) { return p1.Y < p2.Y; }
		)->Y;

		std::vector<Point<int64_t>> transformedPoints;
		transformedPoints.reserve(trenchCorners.size());
		std::transform(
			trenchCorners.begin(),
			trenchCorners.end(),
			std::back_inserter(transformedPoints),
			[xMin, yMin](const Point<int64_t>& p)
			{
				return p.MoveBy(xMin < 0 ? -xMin : 0, yMin < 0 ? -yMin : 0);
			});

		// Area within the trenches via shoelace theorem:
		std::vector<int64_t> subAreas;

		// Process points pairwise:
		auto it1 = transformedPoints.begin(), it2 = transformedPoints.begin() + 1;
		while (it2 != transformedPoints.end())
		{
			const Point<int64_t>& endPoint1 = *it1;
			const Point<int64_t>& endPoint2 = *it2;
			subAreas.emplace_back((endPoint1.X * endPoint2.Y) - (endPoint1.Y * endPoint2.X));

			++it1;
			++it2;
		}

		uint64_t innerArea = std::abs(std::accumulate(subAreas.begin(), subAreas.end(), 0ll) / 2);

		// Add missing area between trenches and actual outer border:
		// - 3 quarter tiles for each outer corner
		// - 1 quarter tile for each inner corner
		// - 1 half tile for each straight tile
		int rightTurns = 0, leftTurns = 0;
		uint64_t straightSteps = 0;

		DigPlan* prevStep = nullptr;
		for (auto& currentStep : digPlans)
		{
			if (prevStep == nullptr)
				prevStep = &currentStep;
			else
			{
				// Count right / left turns:
				if (prevStep->dy == -1 && currentStep.dx == 1 ||
					prevStep->dx == 1 && currentStep.dy == 1 ||
					prevStep->dy == 1 && currentStep.dx == -1 ||
					prevStep->dx == -1 && currentStep.dy == -1)
				{
					++rightTurns;
				}
				else
				{
					++leftTurns;
				}

				prevStep = &currentStep;
			}

			straightSteps += currentStep.Steps - 1;
		}

		// Last turn from last step to initial step:
		if (prevStep->dy == -1 && digPlans[0].dx == 1 ||
			prevStep->dx == 1 && digPlans[0].dy == 1 ||
			prevStep->dy == 1 && digPlans[0].dx == -1 ||
			prevStep->dx == -1 && digPlans[0].dy == -1)
		{
			++rightTurns;
		}
		else
		{
			++leftTurns;
		}

		uint64_t quarterTiles = 0;
		if (rightTurns > leftTurns)
		{
			// Clockwise: right turns are outer corners, left turns are inner corners
			quarterTiles = (rightTurns * 3 + leftTurns + straightSteps * 2);
		}
		else
		{
			// Counter-clockwise: left turns are outer corners, right turns are inner corners
			quarterTiles = (leftTurns * 3 + rightTurns + straightSteps * 2);
		}

		auto actualArea = innerArea + (quarterTiles / 4);
		return actualArea;
	}



	uint64_t LavaductLagoon::ExecutePart1(std::vector<DigPlan> digPlans)
	{
		return GetAreaSize(digPlans, false);
	}

	uint64_t LavaductLagoon::ExecutePart2(std::vector<DigPlan> digPlans)
	{
		return GetAreaSize(digPlans, true);
	}
}
