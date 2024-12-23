#include "ConnectionProcessor.h"

namespace AdventOfCode::Year2024::Day23
{
	std::vector<Connection> ConnectionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Connection> connections;

		for (const std::string& line : input)
		{
			Connection con;
			con.Computer1 = line.substr(0, 2);
			con.Computer2 = line.substr(3);

			if (con.Computer1 > con.Computer2)
				std::swap(con.Computer1, con.Computer2);

			connections.emplace_back(con);
		}

		return connections;
	}
}
