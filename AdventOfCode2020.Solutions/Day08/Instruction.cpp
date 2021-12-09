#include "Instruction.h"

namespace AdventOfCode::Year2020::Day08
{
	Instruction::Instruction(InstrType type, int arg) :
		m_type(type), m_arg(arg), m_wasExecuted(false)
	{}

	bool Instruction::Execute(std::vector<Instruction>::iterator& stackPtr, ExecutionContext& context)
	{
		if (m_wasExecuted)
			return false;

		switch (m_type)
		{
			case InstrType::JMP:
				stackPtr += m_arg;
				break;
			case InstrType::ACC:
				context.Accumulator += m_arg;
				/*fall-through*/
			case InstrType::NOP:
			default:
				stackPtr++;
				break;
		}

		m_wasExecuted = true;
		return true;
	}
}