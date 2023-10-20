#include "PipeProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day12
{
	std::vector<Pipe> PipeProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Pipe> pipes;

		for (const std::string& line : input)
		{
			Pipe p;
			
			std::istringstream iss(line);
			iss >> p.ProgramId;

			std::string arrow;
			iss >> arrow; // discard

			// Connections:
			int connectedPrgm;
			char comma;
			while (iss >> connectedPrgm)
			{
				p.ConnectedTo.push_back(connectedPrgm);
				iss >> comma; // discard
			}

			pipes.emplace_back(p);
		}

		return pipes;
	}
}
