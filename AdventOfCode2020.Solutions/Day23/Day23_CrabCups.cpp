#include "Day23_CrabCups.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day23
{
	CrabCups::CrabCups() : DayT(23, "Crab Cups"), 
		m_allCups(10, Cup(0)), m_currentCup(nullptr), m_minLabel(0), m_maxLabel(0)
	{}

	// Cup objects not created by processor:
	// Because of pointer connections between them, they are allocated on heap
	// and are managed by the day23 class itself
	uint64_t Day23::CrabCups::ExecutePart1(std::vector<int> cupOrder)
	{
		uint64_t res = 0;
		
		// vector size: +1 for 0-element (which is not used, so cups can be accessed with their number directly as index)
		// -> initialized in ctor

		m_minLabel = *std::min_element(cupOrder.begin(), cupOrder.end());
		m_maxLabel = *std::max_element(cupOrder.begin(), cupOrder.end());

		Cup* pCup = nullptr;

		// Each of the next cups is linked to the previous one
		// First 9 elements are already valid, so access via index operator is allowed:
		for (int label : cupOrder)
		{
			m_allCups[label] = Cup(label, pCup);
			if (pCup) pCup->SetNext(&m_allCups[label]); // link the previously created cup to the current one
			pCup = &m_allCups[label];
		}

		// First cup in order will be the initial cup
		m_currentCup = &m_allCups[cupOrder[0]];

		// Close circle:
		m_allCups[cupOrder.back()].SetNext(m_currentCup);

		// Simulate moves:
		for (int n = 0; n < 100; ++n)
			MakeMove();

		// return cup order after the cup "1"
		res = strtoul(GetCurrentCupOrder(1).c_str() + 1, nullptr, 10);

		return res;
	}

	uint64_t Day23::CrabCups::ExecutePart2(std::vector<int> cupOrder)
	{
		// +1 for 0-element (which is not used, so cups can be accessed with their number directly as index)
		m_allCups.reserve(1'000'001);
		m_allCups[0] = Cup(0); // not used

		m_minLabel = *std::min_element(cupOrder.begin(), cupOrder.end());
		m_maxLabel = *std::max_element(cupOrder.begin(), cupOrder.end());

		Cup* pCup = nullptr;

		// Each of the next cups is linked to the previous one
		// First 9 elements are already valid, so access via index operator is allowed:
		for (int label : cupOrder)
		{
			m_allCups[label] = Cup(label, pCup);
			if (pCup) pCup->SetNext(&m_allCups[label]); // link the previously created cup to the current one
			pCup = &m_allCups[label];
		}

		// Fill up cups to 1 million: push in order
		for (int label = m_maxLabel + 1; label <= 1'000'000; ++label)
		{
			m_allCups.emplace_back(Cup(label, pCup));
			pCup->SetNext(&m_allCups[label]);
			pCup = &m_allCups[label];
		}

		m_maxLabel = 1'000'000;

		// First cup in order will be the initial cup
		m_currentCup = &m_allCups[cupOrder[0]];

		// Close circle:
		m_allCups.back().SetNext(m_currentCup);

		// Simulate moves:
		for (int n = 0; n < 10'000'000; ++n)
			MakeMove();

		// Check two cups behind the cup labeled '1':
		uint64_t secondCupLabel = m_allCups[1].GetNext()->GetLabel();
		uint64_t thirdCupLabel = m_allCups[1].GetNext(1)->GetLabel();

		uint64_t res = secondCupLabel * thirdCupLabel;

		return res;
	}

	// ---------------------------------------------------------------------------
	void Day23::CrabCups::MakeMove()
	{
		// The crab picks up the three cups that are immediately clockwise of the current cup. 
		// They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
		Cup* removedCupsBegin = m_currentCup->GetNext();	// start from the cup immeadiately next
		Cup* removedCupsEnd = m_currentCup->GetNext(3);		// new cup to be next to the current cup
		m_currentCup->SetNext(removedCupsEnd);				// removed from the circle

		// The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. 
		// If this would select one of the cups that was just picked up, the crab will keep subtracting one until
		// it finds a cup that wasn't just picked up. If at any point in this process the value goes below the 
		// lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
		int destCupLabel = m_currentCup->GetLabel();		// the subtraction will be made in the loop below:
		bool destOK = true;
		do
		{
			--destCupLabel;
			if (destCupLabel < m_minLabel)	// wrap-around
				destCupLabel = m_maxLabel;

			// Check if label is among the picked cups:
			destOK = true;
			for (Cup* pCup = removedCupsBegin; pCup != removedCupsEnd; pCup = pCup->GetNext())
			{
				if (pCup->GetLabel() == destCupLabel)
				{
					destOK = false;
					break;
				}
			}

		} while (!destOK);

		// The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. 
		// They keep the same order as when they were picked up.
		removedCupsBegin
			->GetNext(1)									// cup at the end of the 3-pack
			->SetNext(m_allCups[destCupLabel].GetNext());	// picked up cups now continue with destination's next
		m_allCups[destCupLabel].SetNext(removedCupsBegin); // destination cup now continues with picked up cups

		 // The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
		m_currentCup = m_currentCup->GetNext();
	}

	// ---------------------------------------------------------------------------
	// Return the current order of the cups, starting from the current cup or from the given label
	std::string Day23::CrabCups::GetCurrentCupOrder(int startLabel)
	{
		std::string out;
		Cup* startCup;
		Cup* pCup;

		if (startLabel)
			pCup = (startCup = &m_allCups[startLabel]);
		else
			pCup = (startCup = m_currentCup);
		do
		{
			out += std::to_string(pCup->GetLabel());
			pCup = pCup->GetNext();
		} while (pCup != startCup);

		return out;
	}
}

