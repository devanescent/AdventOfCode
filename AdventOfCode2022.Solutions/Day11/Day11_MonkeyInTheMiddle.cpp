#include "Day11_MonkeyintheMiddle.h"
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2022::Day11
{
	MonkeyInTheMiddle::MonkeyInTheMiddle() : DayT(11, "Monkey in the Middle") { }

	uint64_t CalculateMonkeyBusinessLevel(std::vector<Monkey>& monkeys, int rounds, std::function<uint64_t(uint64_t)> reduceWorry)
	{
		std::map<int, int> inspectedItems;

		for (int round = 0; round < rounds; ++round)
		{
			for (int monkeyIx = 0; monkeyIx < monkeys.size(); ++monkeyIx)
			{
				Monkey& monkey = monkeys[monkeyIx];

				// Count how many times each monkey inspected items:
				inspectedItems[monkeyIx] += monkey.Items.size();

				while (!monkey.Items.empty())
				{
					uint64_t worryLevel = monkey.InspectItem(monkey.Items.front());
					worryLevel = reduceWorry(worryLevel);

					int targetMonkey = monkey.ThrowItemToMonkey(worryLevel);
					monkeys[targetMonkey].Items.emplace(worryLevel);
					monkey.Items.pop();
				}
			}
		}

		// Monkey business:
		std::vector<uint64_t> inspections;
		std::transform(inspectedItems.begin(), inspectedItems.end(), std::back_inserter(inspections),
			[](const auto& ins)
			{
				return ins.second;
			}
		);

		std::sort(inspections.begin(), inspections.end(), std::greater<>());
		return inspections[0] * inspections[1];
	}

	uint64_t MonkeyInTheMiddle::ExecutePart1(std::vector<Monkey> monkeys)
	{
		return CalculateMonkeyBusinessLevel(monkeys, 20, [](uint64_t worryLevel) { return worryLevel / 3; });
	}

	uint64_t MonkeyInTheMiddle::ExecutePart2(std::vector<Monkey> monkeys)
	{
		// Get product of all division tests for reducing worry levels:
		uint64_t reduceValue = std::accumulate(monkeys.begin(), monkeys.end(), 1ull,
			[](uint64_t factor, const Monkey& m)
			{
				return factor * m.TestDivisor;
			});

		return CalculateMonkeyBusinessLevel(monkeys, 10000, [reduceValue](uint64_t worryLevel) { return worryLevel % reduceValue; });
	}
}
