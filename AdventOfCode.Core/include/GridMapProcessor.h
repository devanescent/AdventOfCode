#pragma once
#include <iterator>
#include <string>
#include <vector>
#include "GridMap.h"

namespace AdventOfCode
{
	// Processor for input in form of a rectangular map
	class GridMapProcessor
	{
	public:
		using container_type = GridMap;
		virtual GridMap Process(std::vector<std::string> input) { return GridMap(std::move(input)); }
	};
}