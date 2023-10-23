#pragma once

namespace AdventOfCode::Year2017::Day18
{
	enum class InstructionType
	{
		PlaySound,
		Set,
		Add,
		Multiply,
		Modulo,
		RecoverSound,
		JumpGreaterZero
	};

	enum ValueType
	{
		None,
		Register,
		Literal
	};

	struct InstructionParameter
	{
		ValueType ValType = ValueType::None;
		int64_t Value = 0ull;
	};

	class SoundInstruction
	{
	public:
		InstructionType Type;
		InstructionParameter Param1;
		InstructionParameter Param2;

		SoundInstruction(InstructionType instrType, InstructionParameter p1, InstructionParameter p2) :
			Type(instrType), Param1(std::move(p1)), Param2(std::move(p2))
		{}
	};
}
