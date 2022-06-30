#pragma once
#include <string>
#include <vector>

namespace AdventOfCode
{
	template <typename TResult, typename TContext, typename TResultContainer = std::vector<TResult>>
	class InputProcessorWithContextBase
	{
	public:
		using result_type = TResult;
		using context_type = TContext;
		using container_type = TResultContainer;
		virtual std::pair<TResultContainer, TContext> Process(std::vector<std::string> input) = 0;
	};
}