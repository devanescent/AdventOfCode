#pragma once

namespace AdventOfCode::Year2022::Day22
{
	enum class MoveInstructionType
	{
		Forward,
		TurnLeft,
		TurnRight
	};

	class MoveInstruction
	{
	public:
		MoveInstructionType MoveType;
		int MoveTiles;
	};
}
