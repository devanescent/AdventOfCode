#pragma once
#include <deque>

namespace AdventOfCode::Year2020::Day22
{
	class Deck
	{
	public:
		Deck(std::deque<uint64_t> cards) :
			m_cards(cards)
		{}

		uint64_t PopTop()
		{
			uint64_t top = m_cards.front();
			m_cards.pop_front();
			return top;
		}

		void AddBack(uint64_t card)
		{
			m_cards.push_back(card);
		}

		bool ContainsCards()
		{
			return !m_cards.empty();
		}

		uint64_t GetScore()
		{
			uint64_t score = 0;
			int k = 1;
			auto cardIt = m_cards.rbegin();

			// Scores: The bottom card in their deck is worth the value of the card multiplied by 1, 
			// the second-from-the-bottom card is worth the value of the card multiplied by 2, and so on.
			for (k, cardIt; cardIt != m_cards.rend(); ++cardIt, ++k)
				score += (*cardIt) * k;

			return score;
		}

		bool operator==(const Deck& other) const
		{
			return m_cards == other.m_cards;
		}

		std::string ToString() const
		{
			std::string out = "";

			for (const auto& card : m_cards)
				out += std::to_string(card) + ",";

			out.pop_back();	// remove last ','
			return out;
		}

	private:
		std::deque<uint64_t> m_cards;
	};
}