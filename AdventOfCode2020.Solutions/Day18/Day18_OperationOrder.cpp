#include "Day18_OperationOrder.h"
#include <numeric>
#include <stack>

namespace AdventOfCode::Year2020::Day18
{
	OperationOrder::OperationOrder() : DayT(18, "Operation Order") {}

	uint64_t OperationOrder::ExecutePart1(std::vector<std::string> expressions)
	{
		return std::accumulate(expressions.cbegin(), expressions.cend(), (uint64_t)0,
			[&](uint64_t res, const std::string& expr) { return res + EvaluateExpression(expr); });
	}

	uint64_t OperationOrder::EvaluateExpression(const std::string& postfixExpression)
	{
		std::stack<int> calc;	// values are pushed here and used for calculations

		for (const char c : postfixExpression)
		{
			if (c == '+')
			{
				int a = calc.top();
				calc.pop();
				int b = calc.top();
				calc.pop();
				calc.push(a + b);
			}
			else if (c == '*')
			{
				int a = calc.top();
				calc.pop();
				int b = calc.top();
				calc.pop();
				calc.push(a * b);
			}
			else
			{
				calc.push(c - '0');
			}
		}

		if (!calc.empty())
			return calc.top();
		else
			return 0;
	}
}



