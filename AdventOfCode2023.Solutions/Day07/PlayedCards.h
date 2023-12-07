#pragma once
#include <map>
#include <string>

namespace AdventOfCode::Year2023::Day07
{
	enum HandType
	{
		Unknown,

		// Lowest strength
		HighCard,
		OnePair,
		TwoPair,
		ThreeOfAKind,
		FullHouse,
		FourOfAKind,
		FiveOfAKind
		// Highest strength
	};

	class PlayedCards
	{
	private:
		bool WithJoker = false;

	public:
		std::string Hand;
		HandType Type = HandType::Unknown;
		int Bid;

		void EnableJoker() { WithJoker = true; }

		void SetHandType()
		{
			// Count cards by type and jokers
			std::map<char, int> cardsByType;
			int jokers = 0;
			for (char c : Hand)
			{
				if (!WithJoker || c != 'J')
					++cardsByType[c];
				else if (WithJoker)
					++jokers;
			}

			if (cardsByType.size() == 0)
			{
				// Hand of all jokers:
				Type = HandType::FiveOfAKind;
				return;
			}
			else if (jokers > 0)
			{
				// Add joker cards to largest group for determining hand type:
				auto largestCardType = std::max_element(cardsByType.begin(), cardsByType.end(),
					[](const auto& cardType1, const auto& cardType2)
					{
						return cardType1.second < cardType2.second;
					});

				largestCardType->second += jokers;
			}

			if (cardsByType.size() == 1)
				Type = HandType::FiveOfAKind;
			else if (cardsByType.size() == 2)
			{
				auto count = cardsByType.begin()->second;
				if (count == 1 || count == 4)
					Type = HandType::FourOfAKind;
				else
					Type = HandType::FullHouse;
			}
			else if (cardsByType.size() == 3)
			{
				auto cardThreeTimes = std::find_if(cardsByType.begin(), cardsByType.end(),
					[](const auto& typeCount) { return typeCount.second == 3; });
				if (cardThreeTimes != cardsByType.end())
					Type = HandType::ThreeOfAKind;
				else
					Type = HandType::TwoPair;
			}
			else if (cardsByType.size() == 4)
				Type = HandType::OnePair;
			else
				Type = HandType::HighCard;
		}

		int CardStrength(char card) const
		{
			switch (card)
			{
				case 'A': return 14;
				case 'K': return 13;
				case 'Q': return 12;
				case 'J': return WithJoker ? 1 : 11;
				case 'T': return 10;
				default:  return card - '0';
			}
		}

		// For sorting:
		bool operator<(const PlayedCards& other) const
		{
			if (Type != other.Type)
				return static_cast<int>(Type) < static_cast<int>(other.Type);
			else
			{
				for (int i = 0; i < 5; ++i)
				{
					if (Hand[i] != other.Hand[i])
						return CardStrength(Hand[i]) < CardStrength(other.Hand[i]);
				}

				return false;
			}
		}
	};
}
