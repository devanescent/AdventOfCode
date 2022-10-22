#pragma once
#include <deque>

namespace AdventOfCode::Year2020::Day22
{
	class Deck
	{
	public:
		Deck(std::deque<int> cards) :
			m_cards(cards)
		{}

		int DrawCard()
		{
			int top = m_cards.front();
			m_cards.pop_front();
			return top;
		}

		void AddCardToBack(int card)
		{
			m_cards.push_back(card);
		}

		int GetCardCount()
		{
			return static_cast<int>(m_cards.size());
		}

		Deck CopyDeck(int numberOfCards)
		{
			return Deck({ m_cards.begin(), m_cards.begin() + numberOfCards });
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
		std::deque<int> m_cards;
	};
}