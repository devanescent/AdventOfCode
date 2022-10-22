#pragma once
#include "ExecutionContext.h"
#include <string>
#include <vector>

namespace AdventOfCode::Year2020::Day08
{
	class Instruction
	{
	public:
		enum class InstrType
		{
			NOP,
			ACC,
			JMP
		};

		Instruction(int index, InstrType type, int arg) :
			m_index(index), m_type(type), m_arg(arg)
		{}

		// Executes the current instruction, returns index of the next instruction to be executed:
		int Execute(ExecutionContext& context) const
		{
			context.SetInstructionAsExecuted(m_index);

			int nextIndex;
			switch (m_type)
			{
				case InstrType::JMP:
					nextIndex = m_index + m_arg;
					break;
				case InstrType::ACC:
					context.ChangeAccumulator(m_arg);
					/*fall-through*/
				case InstrType::NOP:
				default:
					nextIndex = m_index + 1;
					break;
			}

			return nextIndex;
		}

		bool IsJMPorNOP() const
		{
			return (m_type == InstrType::JMP) || (m_type == InstrType::NOP);
		}

		void SwapJMPandNOP()
		{
			if (m_type == InstrType::NOP)
				m_type = InstrType::JMP;
			else if (m_type == InstrType::JMP)
				m_type = InstrType::NOP;
		}

		bool operator==(const Instruction& other) const
		{
			return m_index == other.m_index && m_type == other.m_type && m_arg == other.m_arg;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s: %+d", m_type == InstrType::ACC ? "ACC" : (m_type == InstrType::JMP ? "JMP" : "NOP"), m_arg);
			return std::string(buf);
		}

	private:
		int			m_index;
		InstrType	m_type;
		int			m_arg;
	};
}