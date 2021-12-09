#pragma once
#include "InputProcessor.h"

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
	// non-templated base class in order to use objects from all days in common collection
	class Day
	{
	public:
		virtual				~Day() = default;

		int					GetDayNo() { return m_dayNo; }
		const char*			GetName() { return m_dayName; }

		virtual uint64_t	GetResultOnPart1(const std::vector<std::string> input) = 0;
		virtual uint64_t	GetResultOnPart2(const std::vector<std::string> input) { return 0ull; }

	protected:
		Day(int no, const char* name) :
			m_dayNo(no), m_dayName(name)
		{}

	private:
		int			m_dayNo;
		const char* m_dayName;
	};
}
