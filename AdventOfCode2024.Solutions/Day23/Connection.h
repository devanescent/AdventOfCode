#pragma once
#include <string>

namespace AdventOfCode::Year2024::Day23
{
	struct Connection
	{
		std::string Computer1;
		std::string Computer2;

		bool operator<(const Connection& other) const
		{
			if (Computer1 != other.Computer1)
				return Computer1 < other.Computer1;
			else
				return Computer2 < other.Computer2;
		}

		bool IsEqual(const Connection& other) const
		{
			return (Computer1 == other.Computer1 && Computer2 == other.Computer2)
				|| (Computer1 == other.Computer2 && Computer2 == other.Computer1);
		}

		bool IsConnectedWith(const Connection& other) const
		{
			return Computer1 == other.Computer1 || Computer1 == other.Computer2
				|| Computer2 == other.Computer1 || Computer2 == other.Computer2;
		}

		Connection GetRequired3WayConnection(const Connection& other) const
		{
			if (Computer1 == other.Computer1)
				return { Computer2, other.Computer2 };
			else if (Computer1 == other.Computer2)
				return { Computer2, other.Computer1 };
			else if (Computer2 == other.Computer1)
				return { Computer1, other.Computer2 };
			else if (Computer2 == other.Computer2)
				return { Computer1, other.Computer1 };
			else
				return { };
		}
	};
}