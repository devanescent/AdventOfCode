#pragma once
#include <string>

namespace AdventOfCode::Year2023::Day08
{
	enum Direction
	{
		Left,
		Right
	};

	class NetworkNode
	{
	public:
		std::string Name;
		std::string LeftNode;
		std::string RightNode;

		const std::string& GetNextNode(Direction dir) const
		{
			if (dir == Direction::Left)
				return LeftNode;
			else
				return RightNode;
		}
	};
}
