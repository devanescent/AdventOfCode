#include "PipeMazeProcessor.h"

namespace AdventOfCode::Year2023::Day10
{
	std::pair<std::vector<Pipe>, Point<int>> PipeMazeProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Pipe>, Point<int>> pipeMaze;
		auto& pipes = pipeMaze.first;
		auto& startingPoint = pipeMaze.second;

		for (int y = 0; y < input.size(); ++y)
		{
			for (int x = 0; x < input[y].size(); ++x)
			{
				char p = input[y][x];

				if (p == 'S')
				{
					startingPoint = { x, y };
				}
				else if (p != '.')
				{
					Point<int> pos = { x, y };
					unsigned int connections;
					switch (p)
					{
						case '|': connections = PipeConnection::North | PipeConnection::South; break;
						case '-': connections = PipeConnection::East  | PipeConnection::West;  break;
						case 'L': connections = PipeConnection::North | PipeConnection::East;  break;
						case 'J': connections = PipeConnection::North | PipeConnection::West;  break;
						case 'F': connections = PipeConnection::South | PipeConnection::East;  break;
						case '7': connections = PipeConnection::South | PipeConnection::West;  break;
					}

					pipes.emplace_back(pos, connections);
				}
			}
		}

		return pipeMaze;
	}
}
