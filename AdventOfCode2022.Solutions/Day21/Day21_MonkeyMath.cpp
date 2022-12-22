#include "Day21_MonkeyMath.h"
#include <stack>

namespace AdventOfCode::Year2022::Day21
{
	MonkeyMath::MonkeyMath() : DayT(21, "Monkey Math") { }

	// Get result of a monkey's calculation by finding all required results:
	uint64_t GetMonkeyResult(std::map<std::string, YellingMonkey>& monkeys, const std::string& monkeyName)
	{
		std::stack<std::string> results;

		results.push(monkeyName);
		while (!results.empty())
		{
			YellingMonkey& m = monkeys[results.top()];

			if (m.Result == 0)
			{
				// If result has not been calculated yet, check if both its operands are calculated:
				bool canCalcResult = true;
				if (monkeys[m.Operand1].Result == 0)
				{
					// Operand 1 not calculated:
					canCalcResult = false;
					results.push(m.Operand1);
				}
				if (monkeys[m.Operand2].Result == 0)
				{
					// Operand 2 not calculated:
					canCalcResult = false;
					results.push(m.Operand2);
				}

				if (canCalcResult)
				{
					// Get result of calculation:
					switch (m.Operation)
					{
						case '+': m.Result = monkeys[m.Operand1].Result + monkeys[m.Operand2].Result; break;
						case '-': m.Result = monkeys[m.Operand1].Result - monkeys[m.Operand2].Result; break;
						case '*': m.Result = monkeys[m.Operand1].Result * monkeys[m.Operand2].Result; break;
						case '/': m.Result = monkeys[m.Operand1].Result / monkeys[m.Operand2].Result; break;
					}
					results.pop();
				}
			}
			else
				// Result has already been calculated:
				results.pop();
		}

		return monkeys[monkeyName].Result;
	}


	uint64_t MonkeyMath::ExecutePart1(std::map<std::string, YellingMonkey> monkeys)
	{
		return GetMonkeyResult(monkeys, "root");
	}

	uint64_t MonkeyMath::ExecutePart2(std::map<std::string, YellingMonkey> monkeys)
	{
		// Check a chain of calculations if it contains the "humn":
		auto operationChainContainsHumn = [&](const std::string& operand)
		{
			std::stack<std::string> results;
			results.push(operand);

			while (!results.empty())
			{
				YellingMonkey& m = monkeys[results.top()];
				results.pop();

				if (m.Result == 0)
				{
					if (m.Operand1 != "humn")
						results.push(m.Operand1);
					else
						return true;

					if (m.Operand2 != "humn")
						results.push(m.Operand2);
					else
						return true;
				}				
			}

			return false;
		};

		// Find out which of root's operands is known and get its result,
		// because the other branch has to yield the same result:
		auto& root = monkeys["root"];
		std::pair<std::string, uint64_t> results; // Branch containing the human and required result

		if (!operationChainContainsHumn(root.Operand1))
		{
			// Operand 1 does not contain "humn":
			auto targetResult = GetMonkeyResult(monkeys, root.Operand1);
			results = std::make_pair(root.Operand2, targetResult);
		}
		else if (!operationChainContainsHumn(root.Operand2))
		{
			// Operand 2 does not contain "humn":
			auto targetResult = GetMonkeyResult(monkeys, root.Operand2);
			results = std::make_pair(root.Operand1, targetResult);
		}

		// Calculate all results until the "humn" monkey is found:
		while (results.first != "humn")
		{
			YellingMonkey& m = monkeys[results.first];
			auto targetResult = results.second;

			if (m.Operand1 != "humn" && !operationChainContainsHumn(m.Operand1))
			{
				auto op1Result = GetMonkeyResult(monkeys, m.Operand1);
				switch (m.Operation)
				{
					case '+': results = std::make_pair(m.Operand2, targetResult - op1Result); break;
					case '-': results = std::make_pair(m.Operand2, op1Result - targetResult); break;
					case '*': results = std::make_pair(m.Operand2, targetResult / op1Result); break;
					case '/': results = std::make_pair(m.Operand2, op1Result / targetResult); break;
				}
			}
			else if (m.Operand2 != "humn" && !operationChainContainsHumn(m.Operand2))
			{
				auto op2Result = GetMonkeyResult(monkeys, m.Operand2);
				switch (m.Operation)
				{
					case '+': results = std::make_pair(m.Operand1, targetResult - op2Result); break;
					case '-': results = std::make_pair(m.Operand1, targetResult + op2Result); break;
					case '*': results = std::make_pair(m.Operand1, targetResult / op2Result); break;
					case '/': results = std::make_pair(m.Operand1, targetResult * op2Result); break;
				}
			}
		}

		return results.second;
	}
}
