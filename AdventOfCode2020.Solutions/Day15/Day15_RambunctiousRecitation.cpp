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
		if (!input.empty())
		{
			input.reserve(m_numberOfTurns);						// so that push_back does not invalidate iterators
			std::map<int /*value*/, int /*last pos*/> lookup;	// remember value positions for better performance

			int currentSize;
			while ((currentSize = (int)input.size()) < m_numberOfTurns)
			{
				int lastElem = input.back();
				int prevPos;

				auto lookupIt = lookup.find(lastElem);
				if (lookupIt != lookup.end())
					prevPos = lookupIt->second;
				else
				{
					// Find last element in previous turns (search from back -> reverse iterator)
					// -> will give -1 if item is encountered the first time
					prevPos = input.rend() - std::find(input.rbegin() + 1, input.rend(), lastElem) - 1;
				}

				// Add to lookup:
				lookup[lastElem] = currentSize - 1;

				// Last element has not been used before: add 0 to end
				if (prevPos == -1)
					input.push_back(0);

				// Element has been used before: calculate how many turns ago that was
				else
					input.push_back(currentSize - prevPos - 1);
			}

			return input.back();
		}

		return 0;
	}
}