#pragma once
#include "Day.h"

namespace AdventOfCode::Year2020::Day18
{
	class OperationOrder : public Day
	{
	public:
		OperationOrder();

		uint64_t GetResultOnPart1(std::vector<std::string> infixExpressions) override;
		uint64_t GetResultOnPart2(std::vector<std::string> infixExpressions) override;

	private:
		// Converts a mathematical expression from infix to postfix notation
		std::string Convert(const std::string& expression, bool ignorePrecedence);

		uint64_t EvaluateExpression(const std::string& postfixExpression);
	};
}



