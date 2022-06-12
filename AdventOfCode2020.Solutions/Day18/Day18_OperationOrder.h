#pragma once
#include "DayT.h"
#include "MathExpressionProcessor.h"

namespace AdventOfCode::Year2020::Day18
{
	class OperationOrder : public DayT<MathExpressionProcessor>
	{
	public:
		OperationOrder();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> expressions) override;

	private:
		uint64_t EvaluateExpression(const std::string& postfixExpression);
	};
}



