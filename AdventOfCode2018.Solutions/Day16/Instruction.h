#pragma once
#include "Register.h"
#include <map>

namespace AdventOfCode::Year2018::Day16
{
	class Instruction
	{
	public:
		// Construct from numerical opcode:
		Instruction(OpCode opCode, int input1, int input2, int output) :
			m_OpCode(opCode), m_numericOpCode(static_cast<int>(opCode)), 
			A(input1), B(input2), C(output)
		{ }

		Instruction(int numericOpCode, int input1, int input2, int output) :
			m_OpCode(OpCode::unknown), m_numericOpCode(numericOpCode), A(input1), B(input2), C(output)
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

		int GetNumericOpCode() const { return m_numericOpCode; }
		void SetCorrectOpCode(const std::map<int, OpCode>& opcodeMap)
		{
			if (m_OpCode == OpCode::unknown)
			{
				m_OpCode = opcodeMap.at(m_numericOpCode);
				m_numericOpCode = static_cast<int>(m_OpCode);
			}
		}

		// Returns true if the instruction depends on the contents of the given register, false otherwise
		bool DependsOnReg(int regIx) const
		{
			switch (m_OpCode)
			{
				// Depends on neither register A nor B:
				case OpCode::seti:
					return false;

					// Only depends on register A, B is only used as value:
				case OpCode::addi:
				case OpCode::muli:
				case OpCode::bani:
				case OpCode::bori:
				case OpCode::setr:
				case OpCode::gtri:
				case OpCode::eqri:
					return A == regIx;

					// Only depends on register B, A is only used as value:
				case OpCode::gtir:
				case OpCode::eqir:
					return B == regIx;

					// Depends on register A and B:
				case OpCode::addr:
				case OpCode::mulr:
				case OpCode::banr:
				case OpCode::borr:
				case OpCode::gtrr:
				case OpCode::eqrr:
					return A == regIx || B == regIx;
			}

			return false;
		}

		int GetA() const { return A; }
		int GetB() const { return B; }

	private:
		OpCode m_OpCode;
		int m_numericOpCode; // If opCode is unknown, this value does not relate directly to the corresponding entry in the OpCode enum!

		unsigned int A;
		unsigned int B;
		unsigned int C;

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

				case OpCode::gtir: reg[C] = static_cast<uint64_t>(A > reg[B]); break;
				case OpCode::gtri: reg[C] = static_cast<uint64_t>(reg[A] > B); break;
				case OpCode::gtrr: reg[C] = static_cast<uint64_t>(reg[A] > reg[B]); break;

				case OpCode::eqir: reg[C] = static_cast<uint64_t>(A == reg[B]); break;
				case OpCode::eqri: reg[C] = static_cast<uint64_t>(reg[A] == B); break;
				case OpCode::eqrr: reg[C] = static_cast<uint64_t>(reg[A] == reg[B]); break;
			}
		}
	};
}