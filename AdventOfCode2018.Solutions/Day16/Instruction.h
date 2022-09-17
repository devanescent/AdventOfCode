#pragma once
#include "Register.h"

namespace AdventOfCode::Year2018::Day16
{
	class Instruction
	{
	public:
		Instruction(int opCode, int input1, int input2, int output) :
			OpCode(opCode), A(input1), B(input2), C(output)
		{ }

		Instruction(const std::string instrStr)
		{
			// Format: numbers separated by spaces
			std::istringstream iss(instrStr);
			iss >> OpCode;
			iss >> A;
			iss >> B;
			iss >> C;
		}

		// Do not use the value for OpCode but treat the instruction as the given type:
		Register ApplyToRegisterAs(Day16::OpCode opCode, const Register& inputReg) const
		{
			Register reg(inputReg);
			switch (opCode)
			{
				case OpCode::addr: reg[C] = reg[A] + reg[B]; break;
				case OpCode::addi: reg[C] = reg[A] + B; break;

				case OpCode::mulr: reg[C] = reg[A] * reg[B]; break;
				case OpCode::muli: reg[C] = reg[A] * B; break;

				case OpCode::banr: reg[C] = reg[A] & reg[B]; break;
				case OpCode::bani: reg[C] = reg[A] & reg[B]; break;

				case OpCode::borr: reg[C] = reg[A] | reg[B]; break;
				case OpCode::bori: reg[C] = reg[A] | reg[B]; break;

				case OpCode::setr: reg[C] = reg[A]; break;
				case OpCode::seti: reg[C] = A; break;

				case OpCode::gtir: reg[C] = static_cast<int>(A > reg[B]); break;
				case OpCode::gtri: reg[C] = static_cast<int>(reg[A] > B); break;
				case OpCode::gtrr: reg[C] = static_cast<int>(reg[A] > reg[B]); break;

				case OpCode::eqir: reg[C] = static_cast<int>(A == reg[B]); break;
				case OpCode::eqri: reg[C] = static_cast<int>(reg[A] == B); break;
				case OpCode::eqrr: reg[C] = static_cast<int>(reg[A] == reg[B]); break;
			}

			return reg;
		}

		int GetActualOpCode() const { return OpCode; }

	private:
		int OpCode;
		int A;
		int B;
		int C;
	};
}