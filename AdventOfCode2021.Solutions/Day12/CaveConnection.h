#pragma once
#include <string>

namespace AdventOfCode::Year2021::Day12
{
	class CaveConnection
	{
	public:
		CaveConnection(std::string cave1, std::string cave2) :
			Cave1(cave1), Cave2(cave2)
		{ }

		std::string Cave1;
		std::string Cave2;
	};
}