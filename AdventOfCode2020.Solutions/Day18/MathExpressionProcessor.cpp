#include "MathExpressionProcessor.h"
#include <algorithm>
#include <stack>

namespace AdventOfCode::Year2020::Day18
{
	std::vector<std::string> MathExpressionProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::string> postfixExpressions;
		postfixExpressions.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(postfixExpressions),
			[&](const std::string& infix) { return Convert(infix); });

		return postfixExpressions;
	}

	// Converts a mathematical expression consisting of single-digit numbers and the operators '+', '*', '(' and ')'
	// from infix to postfix notation by using the Shunting-Yard-Algorithm:
	// Note: '+' and '*' have the same operator precedence and are always evaluated from left to right!
	std::string MathExpressionProcessor::Convert(const std::string& expression)
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
					result += operators.top();
					operators.pop();
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
}