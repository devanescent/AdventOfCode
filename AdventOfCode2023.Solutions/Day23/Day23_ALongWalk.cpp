#include "Day23_ALongWalk.h"
#include "Point.h"
#include <queue>
#include <map>
#include <set>
#include <stack>

namespace AdventOfCode::Year2023::Day23
{
	ALongWalk::ALongWalk() : Day(23, "A Long Walk") { }

	enum class Direction
	{
		North,
		East,
		South,
		West
	};

	bool MoveForward(const std::vector<std::string>& trails, const Point<int>& p, Direction dir, Point<int>& next, bool ignoreSlope)
	{
		int mapWidth = trails[0].length();
		int mapHeight = trails.size();

		char slope;
		switch (dir)
		{
			case Direction::North:
				next = p.MoveYBy(-1);
				slope = '^';
				break;
			case Direction::East:
				next = p.MoveXBy(1);
				slope = '>';
				break;
			case Direction::South:
				next = p.MoveYBy(1);
				slope = 'v';
				break;
			case Direction::West:
				next = p.MoveXBy(-1);
				slope = '<';
				break;
		}

		if (!next.CheckBounds(mapWidth, mapHeight))
			return false;

		if (trails[next.Y][next.X] == '#')
			return false;

		return trails[next.Y][next.X] == '.' || ignoreSlope || trails[next.Y][next.X] == slope;
	}

	Direction TurnRight(Direction dir)
	{
		return static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
	}

	Direction TurnLeft(Direction dir)
	{
		return static_cast<Direction>((static_cast<int>(dir) + 3) % 4);
	}


	uint64_t ALongWalk::ExecutePart1(std::vector<std::string> hikingTrails)
	{
		int mapWidth = hikingTrails[0].length();
		int mapHeight = hikingTrails.size();

		Point<int> start{ 1,0 };
		Point<int> end{ mapWidth - 2, mapHeight - 1 };

		struct Progress
		{
			Point<int> Location;
			uint64_t Distance;
			Direction Direction;
		};
		
		std::queue<Progress> q;
		q.emplace(Progress{start, 0, Direction::South});

		std::map<Point<int>, uint64_t> visited;

		uint64_t maxTrail = 0;

		while (!q.empty())
		{
			Progress p = q.front();
			q.pop();

			if (p.Location == end)
				maxTrail = std::max(maxTrail, p.Distance);

			Point<int> next;
			if (MoveForward(hikingTrails, p.Location, p.Direction, next, false))
			{
				if (hikingTrails[p.Location.Y][p.Location.X] != '.')
				{
					// Current position is slope -> next position is a crossing
					auto visIt = visited.find(next);
					if (visIt == visited.end())
					{
						visited[next] = p.Distance + 1;
						q.emplace(Progress{ next, p.Distance + 1, p.Direction });
					}
					else
					{
						if (p.Distance + 1 > visIt->second)
						{
							visIt->second = p.Distance + 1;
							q.emplace(Progress{ next, p.Distance + 1, p.Direction });
						}
					}
				}
				else
				{
					q.emplace(Progress{ next, p.Distance + 1, p.Direction });
				}
			}
			
			Point<int> rightTurn;
			Direction right = TurnRight(p.Direction);
			if (MoveForward(hikingTrails, p.Location, right, rightTurn, false))
			{
				q.emplace(Progress{ rightTurn, p.Distance + 1, right });
			}

			Point<int> leftTurn;
			Direction left = TurnLeft(p.Direction);
			if (MoveForward(hikingTrails, p.Location, left, leftTurn, false))
			{
				q.emplace(Progress{ leftTurn, p.Distance + 1, left });
			}
		}

		return maxTrail;
	}

	uint64_t ALongWalk::ExecutePart2(std::vector<std::string> hikingTrails)
	{
		int mapWidth = hikingTrails[0].length();
		int mapHeight = hikingTrails.size();

		Point<int> start{ 1,0 };
		Point<int> end{ mapWidth - 2, mapHeight - 1 };

		struct Progress
		{
			Point<int> Location;
			uint64_t Distance;
			Direction Direction;

			bool IsCrossing;
			Point<int> LastCrossing;
			uint64_t DistanceToLastCrossing;
		};

		std::queue<Progress> q;
		q.emplace(Progress{ start, 0, Direction::South, false, start, 0 });

		std::set<Point<int>> visited;

		std::map<std::pair<Point<int>, Point<int>>, uint64_t> paths;

		while (!q.empty())
		{
			Progress p = q.front();
			q.pop();
			
			if (p.IsCrossing)
			{
				paths[std::make_pair(p.LastCrossing, p.Location)] = p.DistanceToLastCrossing;

				p.LastCrossing = p.Location;
				p.DistanceToLastCrossing = 0;

				auto visIt = visited.find(p.Location);
				if (visIt == visited.end())
					visited.insert(p.Location);
				else
					continue;
			}
			else if (p.Location == end)
			{
				paths[std::make_pair(p.LastCrossing, p.Location)] = p.DistanceToLastCrossing;
				continue;
			}

			// If current position is slope -> next position is a crossing, if not currently leaving a crossing:
			bool isCrossing = hikingTrails[p.Location.Y][p.Location.X] != '.' && p.LastCrossing.DistanceTo(p.Location) > 1;

			Point<int> next;
			if (MoveForward(hikingTrails, p.Location, p.Direction, next, true))
			{
				q.emplace(Progress{ next, p.Distance + 1, p.Direction, isCrossing, p.LastCrossing, p.DistanceToLastCrossing + 1 });
			}

			Point<int> rightTurn;
			Direction right = TurnRight(p.Direction);
			if (MoveForward(hikingTrails, p.Location, right, rightTurn, true))
			{
				q.emplace(Progress{ rightTurn, p.Distance + 1, right, isCrossing, p.LastCrossing, p.DistanceToLastCrossing + 1 });
			}

			Point<int> leftTurn;
			Direction left = TurnLeft(p.Direction);
			if (MoveForward(hikingTrails, p.Location, left, leftTurn, true))
			{
				q.emplace(Progress{ leftTurn, p.Distance + 1, left, isCrossing, p.LastCrossing, p.DistanceToLastCrossing + 1 });
			}
		}


		std::map<Point<int>, std::vector<std::pair<Point<int>, uint64_t>>> connections;
		for (const auto& pathEntry : paths)
		{
			auto pathStart = pathEntry.first.first;
			auto pathEnd = pathEntry.first.second;

			auto& cons1 = connections[pathStart];
			if (std::find_if(cons1.begin(), cons1.end(), 
				[&pathEnd](const auto& pathWithDist) { return pathWithDist.first == pathEnd; }) == cons1.end())
				cons1.emplace_back(std::make_pair(pathEnd, pathEntry.second));

			auto& cons2 = connections[pathEnd];
			if (std::find_if(cons2.begin(), cons2.end(),
				[&pathStart](const auto& pathWithDist) { return pathWithDist.first == pathStart; }) == cons2.end())
				cons2.emplace_back(std::make_pair(pathStart, pathEntry.second));
		}


		// Check all paths to the end to find the longest:
		struct PathProgress
		{
			Point<int> Location;
			std::set<Point<int>> CurrentPath;
			uint64_t Distance;
		};

		std::stack<PathProgress> pathq;
		std::set<Point<int>> initialPath{ start };
		pathq.emplace(PathProgress{ start, initialPath, 0 });

		uint64_t maxTrail = 0;

		while (!pathq.empty())
		{
			PathProgress pp = pathq.top();
			pathq.pop();

			if (pp.Location == end)
			{
				maxTrail = std::max(maxTrail, pp.Distance);
			}
			else for (const auto& con : connections[pp.Location])
			{
				if (!pp.CurrentPath.contains(con.first))
				{
					auto nextPath = pp.CurrentPath;
					nextPath.insert(con.first);
					pathq.emplace(PathProgress{ con.first, std::move(nextPath), pp.Distance + con.second });
				}
			}
		}

		return maxTrail;
	}
}