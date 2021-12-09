#include "Day23_CrabCups.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day23
{
	CrabCups::CrabCups(int numberOfMoves) : DayT(23, "Crab Cups"), 
		m_numberOfMoves(numberOfMoves)
	{}

	// Cup objects not created by processor:
	// Because of pointer connections between them, they are allocated on heap
	// and are managed by the day23 class itself
	uint64_t Day23::CrabCups::ExecutePart1(std::vector<int> cupOrder)
	{
		uint64_t res = 0;
		if (!cupOrder.empty())
		{
			// +1 for 0-element (which is not used, so cups can be accessed with their number directly as index)
			m_allCups = std::vector<Cup*>(cupOrder.size() + 1, (Cup*)nullptr);

			m_minLabel = *std::min_element(cupOrder.begin(), cupOrder.end());
			m_maxLabel = *std::max_element(cupOrder.begin(), cupOrder.end());

			// First cup in order will be the initial cup
			m_allCups[cupOrder[0]] = (m_currentCup = new Cup(cupOrder[0]));

			// Each of the next cups is linked to the previous one
			Cup* pCup = m_currentCup;
			for (auto cupIt = cupOrder.begin() + 1; cupIt != cupOrder.end(); ++cupIt)
			{
				pCup = new Cup(*cupIt, pCup);
				m_allCups[*cupIt] = pCup;
			}

			// Close circle:
			m_allCups[cupOrder.back()]->SetNext(m_currentCup);

			// Execute the rules:
			for (int n = 0; n < m_numberOfMoves; ++n)
				MakeMove();

			// return cup order after the cup "1"
			res = strtoul(GetCurrentCupOrder(1).c_str() + 1, nullptr, 10);

			// Clean-up
			for (auto pCup : m_allCups)
				delete pCup;
		}

		return res;
	}

	// ---------------------------------------------------------------------------
	void Day23::CrabCups::MakeMove()
	{
		// The crab picks up the three cups that are immediately clockwise of the current cup. 
		// They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
		Cup* removedCupsBegin = m_currentCup->GetNext();	// start from the cup immeadiately next
		Cup* removedCupsEnd = m_currentCup->GetNext(3);		// new cup to be next to the current cup
		m_currentCup->SetNext(removedCupsEnd);					// removed from the circle

		// The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. 
		// If this would select one of the cups that was just picked up, the crab will keep subtracting one until
		// it finds a cup that wasn't just picked up. If at any point in this process the value goes below the 
		// lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
		int destCupLabel = m_currentCup->GetLabel();	// the subtraction will be made in the loop below:
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
		removedCupsBegin->GetNext(1)->SetNext(m_allCups[destCupLabel]->GetNext());	// picked up cups now continue with destination's next
		m_allCups[destCupLabel]->SetNext(removedCupsBegin); // destination cup now continues with picked up cups

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
			pCup = (startCup = m_allCups[startLabel]);
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

