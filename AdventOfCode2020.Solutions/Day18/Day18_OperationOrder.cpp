#include "Day18_OperationOrder.h"
#include <algorithm>
#include <numeric>
#include <stack>

namespace AdventOfCode::Year2020::Day18
{
	OperationOrder::OperationOrder() : Day(18, "Operation Order") {}

	uint64_t OperationOrder::GetResultOnPart1(std::vector<std::string> infixExpressions)
	{
		// Transform from infix to postfix notation:
		std::vector<std::string> postfixExpressions;
		postfixExpressions.reserve(infixExpressions.size());

		std::transform(infixExpressions.begin(), infixExpressions.end(), std::back_inserter(postfixExpressions),
			[&](const std::string& infix) { return Convert(infix, true); });

		// Sum up all individual results:
		return std::accumulate(postfixExpressions.cbegin(), postfixExpressions.cend(), 0ull,
			[&](uint64_t res, const std::string& expr) { return res + EvaluateExpression(expr); });
	}

	uint64_t OperationOrder::GetResultOnPart2(std::vector<std::string> infixExpressions)
	{
		// Transform from infix to postfix notation:
		std::vector<std::string> postfixExpressions;
		postfixExpressions.reserve(infixExpressions.size());

		std::transform(infixExpressions.begin(), infixExpressions.end(), std::back_inserter(postfixExpressions),
			[&](const std::string& infix) { return Convert(infix, false); });

		// Sum up all individual results:
		return std::accumulate(postfixExpressions.cbegin(), postfixExpressions.cend(), 0ull,
			[&](uint64_t res, const std::string& expr) { return res + EvaluateExpression(expr); });
	}

	// Converts a mathematical expression consisting of single-digit numbers and the operators '+', '*', '(' and ')'
	// from infix to postfix notation by using the Shunting-Yard-Algorithm:
	
	// If 'ignorePrecedence' is true, '+' and '*' have the same operator precedence and are always evaluated from left to right!
	// Otherwise, '+' has precedence over '*'!
	std::string OperationOrder::Convert(const std::string& expression, bool ignorePrecedence)
	{
		std::stack<char> operators;
		std::string result;
		result.reserve(expression.size());

		// Parse the expression:
		for (const char c : expression)
		{
			if (c == ' ')
				continue;
			else if (c == '+' || c == '*')
			{
				// terms are evaluated from left to right, therefore the previous operator has to evaluated before
				if (!operators.empty() && (operators.top() == '+' || operators.top() == '*'))
				{
					// When handling precedence, only pop the stack if the operator on top has higher precedence
					// (in this case the '+' operator)
					if (ignorePrecedence || operators.top() == '+') 
					{
						result += operators.top();
						operators.pop();
					}
				}

				operators.push(c);
			}
			else if (c == '(')
			{
				operators.push(c);
			}
			else if (c == ')')
			{
				while (operators.top() != '(')
				{
					result += operators.top();
					operators.pop();
				}
				operators.pop();	// discard '('
			}
			else
			{
				result += c;
			}
		}

		// Add remaining operators:
		while (!operators.empty())
		{
			result += operators.top();
			operators.pop();
		}

		return result;
	}

	uint64_t OperationOrder::EvaluateExpression(const std::string& postfixExpression)
	{
		std::stack<uint64_t> calc;	// values are pushed here and used for calculations

		for (const char c : postfixExpression)
		{
			if (c == '+')
			{
				uint64_t a = calc.top();
				calc.pop();
				uint64_t b = calc.top();
				calc.pop();
				calc.push(a + b);
			}
			else if (c == '*')
			{
				uint64_t a = calc.top();
				calc.pop();
				uint64_t b = calc.top();
				calc.pop();
				calc.push(a * b);
			}
			else
			{
				calc.push(static_cast<uint64_t>(c - '0'));
			}
		}

		if (!calc.empty())
			return calc.top();
		else
			return 0;
	}
}



