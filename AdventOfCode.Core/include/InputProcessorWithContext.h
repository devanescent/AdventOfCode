#pragma once
#include <string>
#include <vector>

namespace AdventOfCode
{
	template <class TResult, class TContext>
	class InputProcessorWithContextBase
	{
	public:
		using result_type = TResult;
		using context_type = TContext;
		virtual std::pair<std::vector<TResult>, TContext> Process(std::vector<std::string> input) = 0;
	};
}