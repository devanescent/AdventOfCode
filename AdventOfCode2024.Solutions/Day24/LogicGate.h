#pragma once

namespace AdventOfCode::Year2024::Day24
{
	enum class LogicGateType
	{
		AND,
		OR,
		XOR
	};

	class LogicGate
	{
	public:
		std::string Input1;
		std::string Input2;
		std::string Output;
		LogicGateType Type;
	};
}
