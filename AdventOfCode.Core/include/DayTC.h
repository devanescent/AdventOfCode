#pragma once
#include "DayBase.h"
#include "InputProcessorWithContext.h"

namespace AdventOfCode
{
	//  templated base class with additional object (context) besides the list
	template <typename TProcessor, typename TResult1 = uint64_t, typename TResult2 = TResult1>
	class DayTC : public DayBase
	{
	public:
		virtual ~DayTC() = default;

		// Override for processing string input - delegates to specialized processor
		AoCResult GetResultOnPart1(std::vector<std::string> input) override
		{
			std::pair<typename TProcessor::container_type, typename TProcessor::context_type> res = m_proc.Process(input);
			return ExecutePart1(res.first, res.second);
		}

		// Override for processing string input - delegates to specialized processor
		AoCResult GetResultOnPart2(std::vector<std::string> input) override
		{
			std::pair<typename TProcessor::container_type, typename TProcessor::context_type> res = m_proc.Process(input);
			return ExecutePart2(res.first, res.second);
		}

	protected:
		// Constructor
		DayTC(int no, const char* name) : DayBase(no, name) {}

		// Process specific input - to be overwritten by the derived class
		virtual TResult1 ExecutePart1(typename TProcessor::container_type input, typename TProcessor::context_type ctx) = 0;
		virtual TResult2 ExecutePart2(typename TProcessor::container_type input, typename TProcessor::context_type ctx) { return TResult2{}; }

	private:
		TProcessor m_proc;
	};
}
