#pragma once
#include "Register.h"

namespace AdventOfCode::Year2018::Day16
{
	class Instruction
	{
	public:
		// Construct from numerical opcode:
		Instruction(OpCode opCode, int input1, int input2, int output) :
			m_OpCode(opCode), A(input1), B(input2), C(output)
		{ }

		// Do not use the instruction's opcode, but treat the instruction as the given type
		// Copies the given register before applying
		template <int N>
		Register<N> ApplyToRegisterAs(OpCode opCode, Register<N> reg) const
		{
			ApplyOpCode(opCode, reg);
			return reg;
		}

		// Use the instruction's opcode:
		// Edits the given register in place
		template <int N>
		void ApplyToRegister(Register<N>& reg) const
		{
			ApplyOpCode(m_OpCode, reg);
		}

		OpCode GetActualOpCode() const { return m_OpCode; }

	private:
		OpCode m_OpCode;
		int A;
		int B;
		int C;

		template <int N>
		void ApplyOpCode(OpCode opCode, Register<N>& reg) const
		{
			switch (opCode)
			{
				case OpCode::addr: reg[C] = reg[A] + reg[B]; break;
				case OpCode::addi: reg[C] = reg[A] + B; break;

				case OpCode::mulr: reg[C] = reg[A] * reg[B]; break;
				case OpCode::muli: reg[C] = reg[A] * B; break;

				case OpCode::banr: reg[C] = reg[A] & reg[B]; break;
				case OpCode::bani: reg[C] = reg[A] & B; break;

				case OpCode::borr: reg[C] = reg[A] | reg[B]; break;
				case OpCode::bori: reg[C] = reg[A] | B; break;

				case OpCode::setr: reg[C] = reg[A]; break;
				case OpCode::seti: reg[C] = A; break;

				case OpCode::gtir: reg[C] = static_cast<int>(A > reg[B]); break;
				case OpCode::gtri: reg[C] = static_cast<int>(reg[A] > B); break;
				case OpCode::gtrr: reg[C] = static_cast<int>(reg[A] > reg[B]); break;

				case OpCode::eqir: reg[C] = static_cast<int>(A == reg[B]); break;
				case OpCode::eqri: reg[C] = static_cast<int>(reg[A] == B); break;
				case OpCode::eqrr: reg[C] = static_cast<int>(reg[A] == reg[B]); break;
			}
		}
	};
}