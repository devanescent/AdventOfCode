#pragma once

namespace AdventOfCode::Year2017::Day08
{
	enum class RegisterModification
	{
		Increase,
		Decrease
	};

	class RegisterInstruction
	{
	public:
		// Value modification
		std::string Name;
		RegisterModification Modification;
		int Value;

		// Condition:
		std::string CompRegName;
		std::string ComRegOp;
		int CompRegValue;

		bool CheckCondition(int actualCompRegValue) const
		{
			if (ComRegOp == "<")
				return actualCompRegValue < CompRegValue;
			else if (ComRegOp == "<=")
				return actualCompRegValue <= CompRegValue;
			else if (ComRegOp == ">")
				return actualCompRegValue > CompRegValue;
			else if (ComRegOp == ">=")
				return actualCompRegValue >= CompRegValue;
			else if (ComRegOp == "==")
				return actualCompRegValue == CompRegValue;
			else if (ComRegOp == "!=")
				return actualCompRegValue != CompRegValue;
			else
				return false;
		}
	};
}
