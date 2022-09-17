#pragma once
#include "Register.h"
#include "Instruction.h"
#include <set>

namespace AdventOfCode::Year2018::Day16
{
	class ComputationSample
	{
	public:
		ComputationSample(Register beforeExec, Register afterExec, Instruction instr) :
			m_beforeExecution(beforeExec), m_afterExecution(afterExec), m_instruction(instr)
		{ }

		std::set<OpCode> GetValidOpCodes() const
		{
			std::set<OpCode> validOpCodes;
			for (int op = 0; op <= 15; ++op)
			{
				OpCode opCode = static_cast<OpCode>(op);
				if (TestOpCode(opCode))
					validOpCodes.insert(opCode);
			}

			return validOpCodes;
		}

		int GetActualOpCode() const { return m_instruction.GetActualOpCode(); }

	private:
		Register m_beforeExecution;
		Register m_afterExecution;
		Instruction m_instruction;

		bool TestOpCode(OpCode op) const
		{
			Register actualResult = m_instruction.ApplyToRegisterAs(op, m_beforeExecution);
			return actualResult == m_afterExecution;
		}
	};

}