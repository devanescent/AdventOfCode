#pragma once
#include <memory>

#include "Day.h"
#include "InputProcessor.h"

namespace AdventOfCode
{
	// -----------------------------------------------------------------------------------
	// templated base class for specific input processing
	template <typename TInput, InputProcessor<TInput> TProcessor>
	class DayT : public Day
	{
	public:
		virtual ~DayT() = default;

		// Override for processing string input - delegates to specialized processor
		uint64_t GetResultOnPart1(const std::vector<std::string> input) override { return ExecutePart1(m_proc.Process(input)); }
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override { return ExecutePart2(m_proc.Process(input)); }

	protected:
		// Constructor
		DayT(int no, const char* name) : Day(no, name) {}

		// Process specific input - to be overwritten by the derived class
		virtual uint64_t ExecutePart1(std::vector<TInput> input) = 0;
		virtual uint64_t ExecutePart2(std::vector<TInput> input) { return 0ull; }

	private:
		TProcessor m_proc;
	};
}