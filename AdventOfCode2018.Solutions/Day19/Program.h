#pragma once
#include "InputProcessorWithContext.h"
#include "..\Day16\Instruction.h"
#include <functional>

namespace AdventOfCode::Year2018::Day19
{
	// Reuse Instruction class from Day 16:
	using Instruction = AdventOfCode::Year2018::Day16::Instruction;

	template<int N>
	using Register = AdventOfCode::Year2018::Day16::Register<N>;

	class Program
	{
	public:
		Program(const std::vector<Instruction>& program) : m_program(program) {}

		// Execute the program until it terminates
		template <int N>
		void Execute(int instrPtrReg, Register<N>& reg)
		{
			int instrPtr = 0;

			// The program halts, if the instruction pointer points outside of the program
			while (instrPtr >= 0 && instrPtr < m_program.size())
			{
				// For each instruction:
				const Instruction& instr = m_program[instrPtr];

				// 1. The instruction pointer's value is written to the bound register just before the instruction is executed
				reg[instrPtrReg] = instrPtr;
				instr.ApplyToRegister(reg);

				// 2. After the instruction finishes, the bound value is written back to the instruction pointer
				instrPtr = static_cast<int>(reg[instrPtrReg]);

				// 3. The instruction pointer's value is moved to the next instruction by adding 1
				++instrPtr;
			}
		}

		// Execute the program until the given condition evaluates to true
		// Predicate receives the index of the currently evaluated instruction
		// -> Returns the current instruction pointer
		template <int N>
		int ExecuteUntil(int instrPtrReg, Register<N>& reg, std::function<bool(int)> predicate, int fromInstr = 0)
		{
			int instrPtr = fromInstr;

			// The program halts, if the instruction pointer points outside of the program
			do
			{
				// For each instruction:
				const Instruction& instr = m_program[instrPtr];

				// 1. The instruction pointer's value is written to the bound register just before the instruction is executed
				reg[instrPtrReg] = instrPtr;
				instr.ApplyToRegister(reg);

				// 2. After the instruction finishes, the bound value is written back to the instruction pointer
				instrPtr = static_cast<int>(reg[instrPtrReg]);

				// 3. The instruction pointer's value is moved to the next instruction by adding 1
				++instrPtr;
			} while (!predicate(instrPtr));

			return instrPtr;
		}

	private:
		const std::vector<Instruction>& m_program;
	};
}