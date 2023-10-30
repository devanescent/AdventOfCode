#pragma once
#include "DayBase.h"

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
// Base class for days that use string input data directly
	template<typename TResult1 = uint64_t, typename TResult2 = TResult1>
	class Day : public DayBase
	{
	public:
		virtual ~Day() = default;

		AoCResult GetResultOnPart1(std::vector<std::string> input) override
		{
			return AoCResult(ExecutePart1(std::move(input)));
		}

		AoCResult GetResultOnPart2(std::vector<std::string> input) override
		{
			return AoCResult(ExecutePart2(std::move(input)));
		}

	protected:
		Day(int no, const char* name) : DayBase(no, name) {}

		// Process input (to be overwritten by concrete classes)
		virtual TResult1 ExecutePart1(std::vector<std::string> input) = 0;
		virtual TResult2 ExecutePart2(std::vector<std::string> input) { return TResult2{}; }
	};
}
