#include "RoomProcessor.h"
#include <algorithm>
#include <map>
#include <stack>
#include <vector>

namespace AdventOfCode::Year2018::Day20
{
	std::vector<Room> RoomProcessor::Process(std::vector<std::string> input)
	{
		// Rooms with doors:
		std::map<Point<int>, DoorFlags> rooms;
		
		// Follow all paths to find all rooms with doors:
		using PointCollection = std::vector<Point<int>>;
		std::stack<PointCollection> pathHeads;
		std::stack<PointCollection> branchStarts;
		std::stack<PointCollection> branchEnds;

		PointCollection origin{ Point(0,0) };
		pathHeads.emplace(origin);

		const std::string& regex = input[0];
		for (char c : regex)
		{
			PointCollection& curPathHeads = pathHeads.top();

			switch (c)
			{
				case 'N':
					for (auto& head : curPathHeads)
					{
						rooms[head] |= DoorFlags::North;
						--head.Y;
						rooms[head] |= DoorFlags::South;
					}
					break;
				case 'E':
					for (auto& head : curPathHeads)
					{
						rooms[head] |= DoorFlags::East;
						++head.X;
						rooms[head] |= DoorFlags::West;
					}
					break;
				case 'S':
					for (auto& head : curPathHeads)
					{
						rooms[head] |= DoorFlags::South;
						++head.Y;
						rooms[head] |= DoorFlags::North;
					}
					break;
				case 'W':
					for (auto& head : curPathHeads)
					{
						rooms[head] |= DoorFlags::West;
						--head.X;
						rooms[head] |= DoorFlags::East;
					}
					break;
				case '(':
				{
					// Remember branch starting point(s):
					branchStarts.push(curPathHeads);

					// Create empty collection of endpoints reached by this branch:
					branchEnds.emplace();
					break;
				}
				case '|':
				{
					// 1. Append path heads to branch endpoints:
					auto& curBranchEnds = branchEnds.top();
					curBranchEnds.insert(curBranchEnds.end(), curPathHeads.begin(), curPathHeads.end());

					// 2. Continue next option from branch start:
					pathHeads.pop();
					pathHeads.push(branchStarts.top());
					break;
				}
				case ')':
				{
					// 1. Append path heads to branch endpoints:
					auto& curBranchEnds = branchEnds.top();
					curBranchEnds.insert(curBranchEnds.end(), curPathHeads.begin(), curPathHeads.end());

					// 2. Sort branch ends and remove duplicates:
					std::sort(curBranchEnds.begin(), curBranchEnds.end());
					curBranchEnds.erase(std::unique(curBranchEnds.begin(), curBranchEnds.end()), curBranchEnds.end());

					// 3. Use branch ends as new heads:
					pathHeads.pop();
					pathHeads.push(curBranchEnds);

					// 4. Clear up branch:
					branchStarts.pop();
					branchEnds.pop();
					break;
				}
				default:
					break;
			}
		}

		std::vector<Room> roomList;
		roomList.reserve(rooms.size());

		std::transform(rooms.begin(), rooms.end(), std::back_inserter(roomList),
			[](const auto& roomEntry)
			{
				return Room(roomEntry.first, roomEntry.second);
			});

		return roomList;
	}
}
