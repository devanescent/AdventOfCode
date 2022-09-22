#pragma once
#include "Register.h"
#include "Instruction.h"
#include <set>

namespace AdventOfCode::Year2018::Day16
{
	class ComputationSample
	{
	public:
		ComputationSample(Register<4> beforeExec, Register<4> afterExec, Instruction instr) :
			m_beforeExecution(beforeExec), m_afterExecution(afterExec), m_instruction(instr)
		{ }

		std::set<OpCode> GetValidOpCodes() const
		{
			std::set<OpCode> validOpCodes;
			for (int op = 1; op <= 16; ++op)
			{
				OpCode opCode = static_cast<OpCode>(op);
				if (TestOpCode(opCode))
					validOpCodes.insert(opCode);
			}

			return validOpCodes;
		}

		int GetNumericOpCode() const { return m_instruction.GetNumericOpCode(); }

	private:
		Register<4> m_beforeExecution;
		Register<4> m_afterExecution;
		Instruction m_instruction;

		bool TestOpCode(OpCode op) const
		{
			Register<4> actualResult = m_instruction.ApplyToRegisterAs(op, m_beforeExecution);
			return actualResult == m_afterExecution;
		}
	};

}