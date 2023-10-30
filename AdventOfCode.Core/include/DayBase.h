#pragma once
#include "AoCResult.h"
#include "InputProcessor.h"

namespace AdventOfCode
{
	// non-templated base class in order to use objects from all days in common collection
	class DayBase
	{
	public:
		virtual				~DayBase() = default;

		int					GetDayNo() { return m_dayNo; }
		const char*			GetName() { return m_dayName; }

		virtual AoCResult GetResultOnPart1(std::vector<std::string> input) = 0;
		virtual AoCResult GetResultOnPart2(std::vector<std::string> input) = 0;

	protected:
		DayBase(int no, const char* name) : m_dayNo(no), m_dayName(name) {}

	private:
		int			m_dayNo;
		const char* m_dayName;
	};
}
