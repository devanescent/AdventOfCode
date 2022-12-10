#pragma once

namespace AdventOfCode::Year2022::Day10
{
	struct CPU
	{
		int Cycle;
		int Register;

		int GetSignalStrength() const { return Cycle * Register; }
	};

	enum class InstructionType
	{
		noop,
		addx
	};

	class Instruction
	{
	public:
		Instruction(InstructionType type, int value = 0) :
			m_type(type), m_value(value)
		{}

		int GetCycles() const
		{
			return m_type == InstructionType::noop ? 1 : 2;
		}

		void ExecuteOnCpu(CPU& cpu) const
		{
			cpu.Register += m_value;
		}

	private:
		InstructionType m_type;
		int m_value;
	};
}
