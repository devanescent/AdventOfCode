#pragma once
#include <string>
#include <vector>

namespace AdventOfCode
{
	// Concept for input processors:
	template <typename TProcessor, typename TProcResult, typename TProcContext>
	concept InputProcessorWithContext = requires(TProcessor p, const std::vector<std::string>&input)
	{
		{ p.Process(input) } -> std::same_as<std::pair<std::vector<TProcResult>, TProcContext>>;
	};

	template <class T, class TContext>
	class InputProcessorWithContextBase
	{
	public:
		virtual std::pair<std::vector<T>, TContext> Process(std::vector<std::string> input) = 0;
	};
}