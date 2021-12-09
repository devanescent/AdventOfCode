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

		Instruction(InstrType type, int arg);
		bool Execute(std::vector<Instruction>::iterator& stackPtr, ExecutionContext& context);

		bool operator==(const Instruction& other) const
		{
			return m_type == other.m_type && m_arg == other.m_arg;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s: %+d", m_type == InstrType::ACC ? "ACC" : (m_type == InstrType::JMP ? "JMP" : "NOP"), m_arg);
			return std::string(buf);
		}

	private:
		InstrType	m_type;
		int			m_arg;
		bool		m_wasExecuted;
	};
}