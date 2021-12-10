#pragma once
#include "Day.h"
#include "InputProcessorWithContext.h"

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
	//  templated base class with additional object (context) besides the list
	template <typename TInput, typename TContext, typename TProcessor>
	class DayTC : public Day
	{
	public:
		virtual ~DayTC() = default;

		// Override for processing string input - delegates to specialized processor
		uint64_t GetResultOnPart1(std::vector<std::string> input) override
		{
			std::pair<std::vector<TInput>, TContext> res = m_proc.Process(input);
			return ExecutePart1(res.first, res.second);
		}

		// Override for processing string input - delegates to specialized processor
		uint64_t GetResultOnPart2(std::vector<std::string> input) override
		{
			std::pair<std::vector<TInput>, TContext> res = m_proc.Process(input);
			return ExecutePart2(res.first, res.second);
		}

	protected:
		// Constructor
		DayTC(int no, const char* name) : Day(no, name) {}

		// Process specific input - to be overwritten by the derived class
		virtual uint64_t ExecutePart1(std::vector<TInput> input, TContext ctx) = 0;
		virtual uint64_t ExecutePart2(std::vector<TInput> input, TContext ctx) { return 0ull; }

	private:
		TProcessor m_proc;
	};
}
