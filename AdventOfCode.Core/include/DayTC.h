#pragma once
#include "Day.h"
#include "InputProcessorWithContext.h"

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
	//  templated base class with additional object (context) besides the list
	template <typename TProcessor>
	class DayTC : public Day
	{
	public:
		virtual ~DayTC() = default;

		// Override for processing string input - delegates to specialized processor
		uint64_t GetResultOnPart1(std::vector<std::string> input) override
		{
			std::pair<typename TProcessor::container_type, typename TProcessor::context_type> res = m_proc.Process(input);
			return ExecutePart1(std::move(res.first), std::move(res.second));
		}

		// Override for processing string input - delegates to specialized processor
		uint64_t GetResultOnPart2(std::vector<std::string> input) override
		{
			std::pair<typename TProcessor::container_type, typename TProcessor::context_type> res = m_proc.Process(input);
			return ExecutePart2(std::move(res.first), std::move(res.second));
		}

	protected:
		// Constructor
		DayTC(int no, const char* name) : Day(no, name) {}

		// Process specific input - to be overwritten by the derived class
		virtual uint64_t ExecutePart1(typename TProcessor::container_type input, typename TProcessor::context_type ctx) = 0;
		virtual uint64_t ExecutePart2(typename TProcessor::container_type input, typename TProcessor::context_type ctx) { return 0ull; }

	private:
		TProcessor m_proc;
	};
}
