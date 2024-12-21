#include "Day21_KeypadConundrum.h"
#include <algorithm>
#include <map>
#include <queue>
#include "Point.h"
#include "Direction.h"

namespace AdventOfCode::Year2024::Day21
{
	using KeyPad = std::map<char, Point<int>>;
	using KeyPair = std::pair<char, char>;
	using KeyPadPaths = std::map<KeyPair, std::vector<std::string>>;
	using KeyPadPathLengths = std::map<KeyPair, uint64_t>;

	KeypadConundrum::KeypadConundrum() : Day(21, "Keypad Conundrum") { }

	struct KeypadProgress
	{
		Point<int> Position;
		std::string Path;
		int DistanceToTarget;

		bool operator<(const KeypadProgress& other) const
		{
			return DistanceToTarget > other.DistanceToTarget;
		}
	};

	bool TryMoveOnKeyPad(const KeyPad& keyPad, const Point<int>& pos, Direction dir, Point<int>& nextPos)
	{
		nextPos = MoveForward(pos, dir);
		auto keyIt = std::find_if(keyPad.begin(), keyPad.end(),
			[&nextPos](const std::pair<const char, Point<int>>& kv)
			{ return kv.second == nextPos; });
		return keyIt != keyPad.end();
	}

	KeyPadPaths GetAllKeypadPaths(const KeyPad& keyPad)
	{
		// Collect paths between every pair of keys on the numpad:
		KeyPadPaths keyPadPaths;

		for (const auto& [keyStart, posStart] : keyPad)
		{
			for (const auto& [keyEnd, posEnd] : keyPad)
			{
				// If the same key need to be pressed again, just hit the 'A' button again
				if (keyStart == keyEnd)
					keyPadPaths[{keyStart, keyEnd}].push_back("A");
				else
				{
					auto distance = posStart.DistanceTo(posEnd);

					std::priority_queue<KeypadProgress> q;
					q.emplace(posStart, "", distance);
					while (!q.empty())
					{
						KeypadProgress progress = q.top();
						q.pop();

						// Wrong direction:
						if (progress.DistanceToTarget > distance || progress.Path.length() > distance)
							continue;

						if (progress.Position == posEnd)
						{
							// Add 'A' for actually pressing the key at the end:
							keyPadPaths[{keyStart, keyEnd}].push_back(progress.Path + 'A');
							continue;
						}

						// Try moving in all directions:
						Point<int> nextPos;

						// Move up:
						if (TryMoveOnKeyPad(keyPad, progress.Position, Direction::Up, nextPos))
							q.emplace(nextPos, progress.Path + "^", nextPos.DistanceTo(posEnd));

						// Move right:
						if (TryMoveOnKeyPad(keyPad, progress.Position, Direction::Right, nextPos))
							q.emplace(nextPos, progress.Path + ">", nextPos.DistanceTo(posEnd));

						// Move down:
						if (TryMoveOnKeyPad(keyPad, progress.Position, Direction::Down, nextPos))
							q.emplace(nextPos, progress.Path + "v", nextPos.DistanceTo(posEnd));

						// Move left:
						if (TryMoveOnKeyPad(keyPad, progress.Position, Direction::Left, nextPos))
							q.emplace(nextPos, progress.Path + "<", nextPos.DistanceTo(posEnd));
					}
				}
			}
		}

		return keyPadPaths;
	}

	KeyPadPathLengths GetNextKeyPadPathLengths(const KeyPadPaths& keyPadPaths, const KeyPadPathLengths& keyPadPathLengths)
	{
		KeyPadPathLengths nextKeyPadPathLengths;
		for (const auto& [keyPair, paths] : keyPadPaths)
		{
			uint64_t minPathLen = UINT64_MAX;
			for (auto& path : paths)
			{
				uint64_t pathLen = 0;
				char currentKey = 'A';
				for (char nextKey : path)
				{
					pathLen += keyPadPathLengths.at({ currentKey, nextKey });
					currentKey = nextKey;
				}

				minPathLen = std::min(minPathLen, pathLen);
			}

			nextKeyPadPathLengths[keyPair] = minPathLen;
		}

		return nextKeyPadPathLengths;
	}

	// Explanation for algorithm here: https://www.reddit.com/r/adventofcode/comments/1hj8380/comment/m35e4tg/
	uint64_t KeypadConundrum::ExecutePart1(std::vector<std::string> keycodes)
	{
		KeyPad dirKeyPad;
		dirKeyPad.emplace('^', Point<int>(1, 0));
		dirKeyPad.emplace('<', Point<int>(0, 1));
		dirKeyPad.emplace('v', Point<int>(1, 1));
		dirKeyPad.emplace('>', Point<int>(2, 1));
		dirKeyPad.emplace('A', Point<int>(2, 0));

		auto dirKeyPadPaths = GetAllKeypadPaths(dirKeyPad);

		// Find the shortest path for each pair of keys when using the last (human-controlled) keypad directly to control the first robot:
		KeyPadPathLengths firstRobotPathLengths;
		for (const auto& [keyPair, paths] : dirKeyPadPaths)
		{
			uint64_t minPathLen = UINT64_MAX;
			for (auto& path : paths)
				minPathLen = std::min(minPathLen, path.length());

			firstRobotPathLengths[keyPair] = minPathLen;
		}

		// Shortest paths used by the first robot to control the second robot:
		auto secondRobotPathLengths = GetNextKeyPadPathLengths(dirKeyPadPaths, firstRobotPathLengths);

		// Paths on numpad:
		KeyPad numKeyPad;
		numKeyPad.emplace('7', Point<int>(0, 0));
		numKeyPad.emplace('8', Point<int>(1, 0));
		numKeyPad.emplace('9', Point<int>(2, 0));
		numKeyPad.emplace('4', Point<int>(0, 1));
		numKeyPad.emplace('5', Point<int>(1, 1));
		numKeyPad.emplace('6', Point<int>(2, 1));
		numKeyPad.emplace('1', Point<int>(0, 2));
		numKeyPad.emplace('2', Point<int>(1, 2));
		numKeyPad.emplace('3', Point<int>(2, 2));
		numKeyPad.emplace('0', Point<int>(1, 3));
		numKeyPad.emplace('A', Point<int>(2, 3));

		auto numKeyPadPaths = GetAllKeypadPaths(numKeyPad);

		// Shortest paths to control the robot on the numpad:
		auto numPadPathLengths = GetNextKeyPadPathLengths(numKeyPadPaths, secondRobotPathLengths);

		uint64_t complexity = 0;
		for (const std::string& keycode : keycodes)
		{
			uint64_t pathLen = 0;
			char currentKey = 'A';
			for (char nextKey : keycode)
			{
				pathLen += numPadPathLengths.at({ currentKey, nextKey });
				currentKey = nextKey;
			}

			auto keycodeVal = std::stoi(keycode.substr(0, 3));
			complexity += keycodeVal * pathLen;
		}

		return complexity;
	}

	uint64_t KeypadConundrum::ExecutePart2(std::vector<std::string> keycodes)
	{
		KeyPad dirKeyPad;
		dirKeyPad.emplace('^', Point<int>(1, 0));
		dirKeyPad.emplace('<', Point<int>(0, 1));
		dirKeyPad.emplace('v', Point<int>(1, 1));
		dirKeyPad.emplace('>', Point<int>(2, 1));
		dirKeyPad.emplace('A', Point<int>(2, 0));

		auto dirKeyPadPaths = GetAllKeypadPaths(dirKeyPad);

		// Find the shortest path for each pair of keys when using the last (human-controlled) keypad directly to control the first robot:
		KeyPadPathLengths firstRobotPathLengths;
		for (const auto& [keyPair, paths] : dirKeyPadPaths)
		{
			uint64_t minPathLen = UINT64_MAX;
			for (auto& path : paths)
				minPathLen = std::min(minPathLen, path.length());

			firstRobotPathLengths[keyPair] = minPathLen;
		}

		// Remaining 24 robots using directional keypads:
		auto nextRobotPathLengths = firstRobotPathLengths;
		for (int i = 0; i < 24; ++i)
		{
			nextRobotPathLengths = GetNextKeyPadPathLengths(dirKeyPadPaths, nextRobotPathLengths);
		}
		
		// Paths on numpad:
		KeyPad numKeyPad;
		numKeyPad.emplace('7', Point<int>(0, 0));
		numKeyPad.emplace('8', Point<int>(1, 0));
		numKeyPad.emplace('9', Point<int>(2, 0));
		numKeyPad.emplace('4', Point<int>(0, 1));
		numKeyPad.emplace('5', Point<int>(1, 1));
		numKeyPad.emplace('6', Point<int>(2, 1));
		numKeyPad.emplace('1', Point<int>(0, 2));
		numKeyPad.emplace('2', Point<int>(1, 2));
		numKeyPad.emplace('3', Point<int>(2, 2));
		numKeyPad.emplace('0', Point<int>(1, 3));
		numKeyPad.emplace('A', Point<int>(2, 3));

		auto numKeyPadPaths = GetAllKeypadPaths(numKeyPad);

		// Shortest paths to control the robot on the numpad:
		auto numPadPathLengths = GetNextKeyPadPathLengths(numKeyPadPaths, nextRobotPathLengths);

		uint64_t complexity = 0;
		for (const std::string& keycode : keycodes)
		{
			uint64_t pathLen = 0;
			char currentKey = 'A';
			for (char nextKey : keycode)
			{
				pathLen += numPadPathLengths.at({ currentKey, nextKey });
				currentKey = nextKey;
			}

			auto keycodeVal = std::stoi(keycode.substr(0, 3));
			complexity += keycodeVal * pathLen;
		}

		return complexity;
	}
}
