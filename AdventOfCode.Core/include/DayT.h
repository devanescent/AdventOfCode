#pragma once
#include "DayBase.h"
#include "InputProcessor.h"
#include <type_traits>

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
	// templated base class for specific input processing
	template <typename TProcessor, typename TResult1 = uint64_t, typename TResult2 = TResult1, bool passOrigDataToDay2 = false>
	class DayT : public DayBase
	{
	public:
		virtual ~DayT() = default;

		AoCResult GetResultOnPart1(std::vector<std::string> input) override { return ExecutePart1(m_proc.Process(std::move(input))); }
		AoCResult GetResultOnPart2(std::vector<std::string> input) override
		{
			if constexpr (!passOrigDataToDay2)
				return ExecutePart2(m_proc.Process(std::move(input)));
			else
				return ExecutePart2WithOrigData(std::move(input));
		}

	protected:
		// Constructor
		DayT(int no, const char* name) : DayBase(no, name) {}

		// Process input:
		virtual TResult1 ExecutePart1(typename TProcessor::container_type input) = 0;
		virtual TResult2 ExecutePart2(typename TProcessor::container_type input) { return TResult2{}; }

		virtual TResult2 ExecutePart2WithOrigData(std::vector<std::string> input) { return TResult2{}; }

		TProcessor m_proc;
	};

}