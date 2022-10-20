#include "Day15_RambunctiousRecitation.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2020::Day15
{
	RambunctiousRecitation::RambunctiousRecitation(int numberOfTurns) : DayT(15, "Rambunctious Recitation"), 
		m_numberOfTurns(numberOfTurns)
	{ }

	uint64_t RambunctiousRecitation::ExecutePart1(std::vector<int> input)
	{
		std::map<uint64_t /*value*/, uint64_t /*turn*/> lookup;	// remember turn in which the value last occured

		// Process starting numbers
		for (uint64_t i = 0; i < input.size(); ++i)
			lookup[input[i]] = i + 1; // Turns are counted from 1 on
			
		// Assuming no duplicates in the initial number, the next number spoken will be zero
		uint64_t currentNum = 0;

		for (uint64_t turn = input.size() + 1; turn < m_numberOfTurns; ++turn)
		{
			auto prev = lookup.find(currentNum);

			if (prev == lookup.end())
			{
				// Number has not occured before
				lookup[currentNum] = turn;
				currentNum = 0;
			}
			else
			{
				// Next number is difference between now and last time it occured
				uint64_t nextNum = turn - prev->second;
				lookup[currentNum] = turn;
				currentNum = nextNum;
			}
		}

		return currentNum;
	}

	uint64_t RambunctiousRecitation::ExecutePart2(std::vector<int> input)
	{
		// Same as Part 1, just with more turns:
		return ExecutePart1(input);
	}
}