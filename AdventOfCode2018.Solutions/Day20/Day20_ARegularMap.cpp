#include "Day20_ARegularMap.h"
#include <map>
#include <queue>

namespace AdventOfCode::Year2018::Day20
{
	ARegularMap::ARegularMap() : DayT(20, "A Regular Map") { }

	// Get a map of all rooms with their distance from the starting room
	// (distance equals numbers of doors between them):
	std::map<Point<int>, int> GetRoomDistanceMap(std::vector<Room>& rooms)
	{
		// Find shortest paths:
		std::priority_queue<Room> roomQueue;
		std::map<Point<int>, int> visited; // Visited rooms by location with shortest distance from origin

		// Get bounds for room locations:
		int roomXmin = INT32_MAX;
		int roomXmax = 0;
		int roomYmin = INT32_MAX;
		int roomYmax = 0;

		for (Room& r : rooms)
		{
			roomXmin = std::min(roomXmin, r.Location.X);
			roomXmax = std::max(roomXmax, r.Location.X);
			roomYmin = std::min(roomYmin, r.Location.Y);
			roomYmax = std::max(roomYmax, r.Location.Y);
		}

		// Place room configuration in vector for easier lookup:
		auto xSize = roomXmax - roomXmin + 1;
		auto ySize = roomYmax - roomYmin + 1;

		std::vector<DoorFlags> doorLookup(xSize * ySize, DoorFlags::None);
		for (Room& r : rooms)
		{
			// Find origin room for starting the path algorithm:
			bool isOrigin = r.Location.X == 0 && r.Location.Y == 0;

			// Shift location by mininma so values are in the range 0..N:
			r.Location = r.Location.MoveBy(-roomXmin, -roomYmin);
			doorLookup[ySize * r.Location.Y + r.Location.X] = r.Doors;

			if (isOrigin)
			{
				r.DistanceFromOrigin = 0;
				roomQueue.push(r);
			}
		}

		while (!roomQueue.empty())
		{
			Room r = roomQueue.top();
			roomQueue.pop();

			// Was room already visited and with a shorter distance, then skip this room:
			auto visIt = visited.find(r.Location);
			if (visIt != visited.end() && visIt->second <= r.DistanceFromOrigin)
				continue;

			// otherwise update distance or insert room:
			else if (visIt != visited.end())
				visIt->second = r.DistanceFromOrigin;
			else
				visited.emplace(r.Location, r.DistanceFromOrigin);

			// Use all available doors:
			DoorFlags doors = doorLookup[ySize * r.Location.Y + r.Location.X];

			if (doors & DoorFlags::North)
				roomQueue.emplace(r.Location.MoveYBy(-1), DoorFlags::None, r.DistanceFromOrigin + 1);

			if (doors & DoorFlags::East)
				roomQueue.emplace(r.Location.MoveXBy(1), DoorFlags::None, r.DistanceFromOrigin + 1);

			if (doors & DoorFlags::South)
				roomQueue.emplace(r.Location.MoveYBy(1), DoorFlags::None, r.DistanceFromOrigin + 1);

			if (doors & DoorFlags::West)
				roomQueue.emplace(r.Location.MoveXBy(-1), DoorFlags::None, r.DistanceFromOrigin + 1);
		}

		return visited;
	}


	uint64_t ARegularMap::ExecutePart1(std::vector<Room> rooms)
	{
		auto map = GetRoomDistanceMap(rooms);

		// Find room with largest distance from origin:
		auto maxIt = std::max_element(map.begin(), map.end(),
			[](const auto& r1, const auto& r2)
			{
				return r1.second < r2.second;
			});

		return maxIt->second;
	}

	uint64_t ARegularMap::ExecutePart2(std::vector<Room> rooms)
	{
		auto map = GetRoomDistanceMap(rooms);

		// Find number of rooms with at least a distance of 1000
		// (i.e. require 1000 doors to pass through to reach):
		return std::count_if(map.begin(), map.end(),
			[](const auto& r)
			{
				return r.second >= 1000;
			});
	}
}
