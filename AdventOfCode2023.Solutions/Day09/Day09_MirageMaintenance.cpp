#include "Day09_MirageMaintenance.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2023::Day09
{
	MirageMaintenance::MirageMaintenance() : DayT(9, "Mirage Maintenance") { }

	enum ExtrapolationType
	{
		Forward,
		Backward
	};

	int64_t ExtrapolateValue(const ValueHistory& history, ExtrapolationType extraType)
	{
		// Remember first / last value of each sequence during computation for extrapolation:
		std::vector<int64_t> lastValues;
		
		// Add first / last value from original sequence
		lastValues.push_back(extraType == ExtrapolationType::Forward ?
			history.Values.back() : 
			history.Values.front());

		bool seqOfEqualVals = false;
		std::vector<int64_t> currentSequence = history.Values;
		do
		{
			std::vector<int64_t> diffs;
			std::adjacent_difference(currentSequence.begin(), currentSequence.end(), std::back_inserter(diffs));

			// Ignore first value in diffs, as std::adjacent_difference()
			// just copies the first value in the sequence:
			currentSequence = { diffs.begin() + 1, diffs.end() };

			lastValues.push_back(extraType == ExtrapolationType::Forward ?
				currentSequence.back() :
				currentSequence.front());

			// Check that all values in this new sequence are equal (by checking every value
			// if equal to the first value of the sequence)
			seqOfEqualVals = std::all_of(currentSequence.begin(), currentSequence.end(),
				[cmp = currentSequence[0]](auto val) { return val == cmp; });

		} while (!seqOfEqualVals);


		// Combine the differences in reverse order, until the extrapolated value for the original sequence is found
		int64_t extrapol = 0;
		for (auto exIt = lastValues.rbegin(); exIt != lastValues.rend(); ++exIt)
		{
			if (extraType == ExtrapolationType::Forward)
				extrapol = *exIt + extrapol;
			else
				extrapol = *exIt - extrapol;
		}

		return extrapol;
	}


	uint64_t MirageMaintenance::ExecutePart1(std::vector<ValueHistory> valueHistories)
	{
		return std::accumulate(valueHistories.begin(), valueHistories.end(), 0ll,
			[](int64_t extrapolatedSum, const ValueHistory& history)
			{
				return extrapolatedSum + ExtrapolateValue(history, ExtrapolationType::Forward);
			});
	}

	uint64_t MirageMaintenance::ExecutePart2(std::vector<ValueHistory> valueHistories)
	{
		return std::accumulate(valueHistories.begin(), valueHistories.end(), 0ll,
			[](int64_t extrapolatedSum, const ValueHistory& history)
			{
				return extrapolatedSum + ExtrapolateValue(history, ExtrapolationType::Backward);
			});
	}
}
