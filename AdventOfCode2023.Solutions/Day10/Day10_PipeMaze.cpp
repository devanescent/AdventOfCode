#include "Day10_PipeMaze.h"
#include <algorithm>
#include <map>
#include <set>

namespace AdventOfCode::Year2023::Day10
{
	PipeMaze::PipeMaze() : DayTC(10, "Pipe Maze") { }

	// Helper methods for moving between points via pipe:
	Point<int> MoveFromPoint(const Point<int>& p, PipeConnection direction)
	{
		switch (direction)
		{
			case PipeConnection::North: return p.MoveYBy(-1);
			case PipeConnection::East:  return p.MoveXBy(+1);
			case PipeConnection::South: return p.MoveYBy(+1);
			case PipeConnection::West:  return p.MoveXBy(-1);
			default:                    return p;
		}
	}

	uint64_t PipeMaze::ExecutePart1(std::vector<Pipe> pipes, Point<int> startingPoint)
	{
		// Organize by position:
		std::map<Point<int>, Pipe> pipeLookup;
		for (const auto& pipe : pipes)
		{
			pipeLookup[pipe.Position] = pipe;
		}

		// Get starting point connections:
		PipeConnection loop1Dir = PipeConnection::None, loop2Dir = PipeConnection::None;

		for (auto&& connectionPoint : startingPoint.GetSurroundingPoints(false))
		{
			auto pipeIt = pipeLookup.find(connectionPoint);
			if (pipeIt != pipeLookup.end())
			{
				loop1Dir == PipeConnection::None ?
					loop1Dir = pipeIt->second.GetConnectionFrom(startingPoint) :
					loop2Dir = pipeIt->second.GetConnectionFrom(startingPoint);
			}
		}

		// Follow both directions along the loop:
		Point<int> loop1 = startingPoint, loop2 = startingPoint;
		uint64_t moveDistance = 0;

		std::set<Point<int>> loopPoints;
		
		bool loopClosed = false;
		do
		{
			++moveDistance;

			loop1 = MoveFromPoint(loop1, loop1Dir);
			loopPoints.insert(loop1);
			loop1Dir = pipeLookup[loop1].MoveThrough(loop1Dir);

			loop2 = MoveFromPoint(loop2, loop2Dir);

			if (loopPoints.contains(loop2))
				loopClosed = true;
			else
			{
				loopPoints.insert(loop2);
				loop2Dir = pipeLookup[loop2].MoveThrough(loop2Dir);
			}

		} while (!loopClosed);

		return moveDistance;
	}

	uint64_t PipeMaze::ExecutePart2(std::vector<Pipe> pipes, Point<int> startingPoint)
	{
		// Organize by position:
		std::map<Point<int>, Pipe> pipeLookup;
		for (const auto& pipe : pipes)
		{
			pipeLookup[pipe.Position] = pipe;
		}

		// Find loop, walk in one of the two connecting directions:
		PipeConnection loopDir = PipeConnection::None;

		for (auto&& connectionPoint : startingPoint.GetSurroundingPoints(false))
		{
			auto pipeIt = pipeLookup.find(connectionPoint);
			if (pipeIt != pipeLookup.end())
			{
				loopDir = pipeIt->second.GetConnectionFrom(startingPoint);
				if (loopDir != PipeConnection::None)
					break;
			}
		}

		// Walk the loop:
		std::set<Point<int>> loopPoints;
		Point<int> loopPos = startingPoint;
		do
		{
			// Add current point to loop (including the starting point):
			loopPoints.insert(loopPos);

			// Next point
			loopPos = MoveFromPoint(loopPos, loopDir);
			loopDir = pipeLookup[loopPos].MoveThrough(loopDir);

		} while (loopPos != startingPoint);

		// Bounding box of loop:
		auto xBounds = std::minmax_element(loopPoints.begin(), loopPoints.end(),
			[](const auto& p1, const auto& p2) { return p1.X < p2.X; });
		int xMin = xBounds.first->X;
		int xMax = xBounds.second->X;

		auto yBounds = std::minmax_element(loopPoints.begin(), loopPoints.end(),
			[](const auto& p1, const auto& p2) { return p1.Y < p2.Y; });
		int yMin = yBounds.first->Y;
		int yMax = yBounds.second->Y;


		// For each point within the bounds that is not part of the loop,
		// shoot a "ray" in an arbitrary direction (e.g. down).
		
		// Count the number of times it crosses the loop: if this number is
		// odd, the point is within the loop; if it is even, the point is outside
		// (see https://en.wikipedia.org/wiki/Point_in_polygon)

		// To count the crossings, count the number of east / west connections 
		// of all the points along the ray. Only a pair of one east and
		// one west conection counts as a crossing.

		// Example 1: From point P, in the downwards direction there are two 
		//            east connections, but no west connections: no crossings
		//            (the loop could be pulled aside)
		// 
		// Example 2: This has one east and one west direction, so counts as one
		//            crossing (the S-bend could be stretched to a straight line)
		//
		// (1)      (2)
		// .....    .....
		// ..P..    ..P..
		// ..F--    ..F--
		// ..L--    ..|..
		// .....    --J..

		uint64_t insideArea = 0;
		for (int y = yMin; y <= yMax; ++y)
		{
			for (int x = xMin; x <= xMax; ++x)
			{
				if (!loopPoints.contains({ x, y }))
				{
					int eastCons = 0, westCons = 0;

					// Move down:
					for (int dy = 1; y + dy <= yMax; ++dy)
					{
						auto crossIt = loopPoints.find({ x, y + dy });
						if (crossIt != loopPoints.end())
						{
							auto cons = pipeLookup[*crossIt].Connections;
							eastCons += (cons & PipeConnection::East) ? 1 : 0;
							westCons += (cons & PipeConnection::West) ? 1 : 0;
						}
					}

					// If the loop was crossed an odd number of times,
					// the current point is inside the loop:
					int crossings = std::min(eastCons, westCons);
					if (crossings % 2 == 1)
						++insideArea;
				}
			}
		}

		return insideArea;


	}
}
