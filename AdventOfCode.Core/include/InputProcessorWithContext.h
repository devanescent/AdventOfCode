#pragma once
#include <string>
#include <vector>

namespace AdventOfCode
{
	template <class T, class TContext>
	class InputProcessorWithContextBase
	{
	public:
		virtual std::pair<std::vector<T>, TContext> Process(std::vector<std::string> input) = 0;
	};
}