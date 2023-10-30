#include "Day05_SupplyStacks.h"
#include <stack>

namespace AdventOfCode::Year2022::Day05
{
	SupplyStacks::SupplyStacks() : DayTC(5, "Supply Stacks") { }

	std::string SupplyStacks::ExecutePart1(std::vector<CraneStep> steps, CrateStacks stacks)
	{
		for (const auto& step : steps)
		{
			// Move one stack at a time:
			for (int i = 0; i < step.NoOfCrates; ++i)
			{
				Crate c = stacks[step.FromStack - 1].top();
				stacks[step.FromStack - 1].pop();
				stacks[step.ToStack - 1].push(c);
			}
		}

		std::string result;
		for (const auto& stack : stacks)
		{
			result.push_back(stack.top());
		}

		return result;
	}

	std::string SupplyStacks::ExecutePart2(std::vector<CraneStep> steps, CrateStacks stacks)
	{
		// Move multiple stacks at the same time (via temp stack)
		std::stack<Crate> temp;

		for (const auto& step : steps)
		{
			// Move crates to temp stack (this reverses their order):
			for (int i = 0; i < step.NoOfCrates; ++i)
			{
				Crate c = stacks[step.FromStack - 1].top();
				stacks[step.FromStack - 1].pop();
				temp.push(c);
			}

			// Move from temp stack to target stack (reverses order again which makes it equal to the initial order):
			while (!temp.empty())
			{
				Crate c = temp.top();
				temp.pop();
				stacks[step.ToStack - 1].push(c);
			}
		}

		std::string result;
		for (const auto& stack : stacks)
		{
			result.push_back(stack.top());
		}

		return result;
	}
}
