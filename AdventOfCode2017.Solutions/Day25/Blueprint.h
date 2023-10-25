#pragma once

namespace AdventOfCode::Year2017::Day25
{
	enum class CursorMovement
	{
		Right,
		Left
	};

	class Blueprint
	{
	public:
		// This blueprint applies, when the current state and value 
		// are equal to the following fields:
		char StateCondition;
		int ValueCondition;

		// Apply the following changes:
		int ValueWritten;
		CursorMovement CursorMovement;
		char NextState;
	};
}
