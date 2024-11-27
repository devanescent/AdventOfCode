#pragma once

namespace AdventOfCode::Year2021::Day24
{
	enum class InstructionType
	{
		Input,
		Add,
		Multiply,
		Divide,
		Modulo,
		Equal
	};

	class AluInstruction
	{
	public:
		InstructionType Operation;
		std::string Operand1;
		std::string Operand2;

		AluInstruction(InstructionType op, std::string arg1, std::string arg2) :
			Operation(op), Operand1(std::move(arg1)), Operand2(std::move(arg2))
		{ }
	};
}
