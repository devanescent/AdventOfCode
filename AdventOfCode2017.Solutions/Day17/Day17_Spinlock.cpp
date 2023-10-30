#include "Day17_Spinlock.h"
#include <list>

namespace AdventOfCode::Year2017::Day17
{
	Spinlock::Spinlock() : Day(17, "Spinlock") { }

	uint64_t Spinlock::ExecutePart1(std::vector<std::string> input)
	{
		int steps = std::stoi(input[0]);

		std::vector<int> circularBuffer{ 0 };
		auto currentPos = 0;

		for (int n = 1; n <= 2017; ++n)
		{
			// Move forward:
			currentPos = (currentPos + steps) % circularBuffer.size();

			// Insert after:
			auto insertPos = circularBuffer.begin() + currentPos + 1;
			circularBuffer.insert(insertPos, n);

			++currentPos;
		}

		// Value after last insertion:
		auto valueAfter = circularBuffer.begin() + currentPos + 1;
		if (valueAfter == circularBuffer.end())
			valueAfter = circularBuffer.begin();

		return *valueAfter;
	}

	uint64_t Spinlock::ExecutePart2(std::vector<std::string> input)
	{
		int steps = std::stoi(input[0]);
		auto currentPos = 0;

		int valueAfterZero;
		for (int n = 1; n <= 50'000'000; ++n)
		{
			// Move forward:
			currentPos = (currentPos + steps) % n;

			// If value is inserted after 0 (currentPos is 0), remember last value that was inserted:
			if (currentPos == 0)
				valueAfterZero = n;

			++currentPos;
		}

		return valueAfterZero;
	}
}
