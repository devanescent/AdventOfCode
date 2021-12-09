#pragma once
#include <iterator>
#include <string>
#include <vector>

namespace AdventOfCode
{
	// Concept for input processors:
	template <typename TProcessor, typename TProcResult>
	concept InputProcessor = requires(TProcessor p, const std::vector<std::string>& input)
	{
		{ p.Process(input) } -> std::same_as<std::vector<TProcResult>>;
	};

	// Base class for input processors
	template <typename TResult>
	class InputProcessorBase
	{
	public:
		virtual std::vector<TResult> Process(std::vector<std::string> input) = 0;

	protected:
		// Joins sets of lines together; sets are seperated by empty lines
		// Optionally, includes a blank between joined lines
		std::vector<std::string> JoinLines(std::vector<std::string> input, bool insertSpace = false)
		{
			std::vector<std::string> sets;

			std::string currentSet;
			for (const std::string& line : input)
			{
				if (!line.empty())
				{
					if (insertSpace && !currentSet.empty())
						currentSet.append(" ");
					currentSet.append(line);
				}
				else
				{
					sets.push_back(currentSet);
					currentSet.clear();
				}
			}

			// last entry
			if (!currentSet.empty())
				sets.push_back(currentSet);

			return sets;
		}
	};
}