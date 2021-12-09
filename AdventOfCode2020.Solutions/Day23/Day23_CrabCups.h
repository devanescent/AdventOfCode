#pragma once
#include "DayT.h"
#include "Cup.h"
#include "IntProcessor.h"

namespace AdventOfCode::Year2020::Day23
{
	class CrabCups : public DayT<int, IntProcessor<IntProcessingMode::ValuesAsDigits>>
	{
	public:
		CrabCups(int numberOfMoves);

	protected:
		uint64_t ExecutePart1(std::vector<int> cupOrder) override;

	private:
		void MakeMove();
		std::string GetCurrentCupOrder(int startLabel = 0);

		int					m_numberOfMoves;
		std::vector<Cup*>	m_allCups; // for easier access to a cup by number
		Cup*				m_currentCup;
		int					m_minLabel, m_maxLabel;	// for overflow while determining the next cup after a move
	};
}


