#include "Day09_MarbleMania.h"
#include <algorithm>
#include <list>

namespace AdventOfCode::Year2018::Day09
{
	MarbleMania::MarbleMania() : Day(9, "Marble Mania")
	{}

	// Update position of current marble in clockwise direction:
	void AdvanceClockwise(std::list<int>& marbles, std::list<int>::iterator& currentMarble, int advance)
	{
		for (int i = 0; i < advance; ++i)
		{
			currentMarble++;
			if (currentMarble == marbles.end())
				currentMarble = marbles.begin();
		}
	}

	// Update position of current marble in counter-clockwise direction:
	void AdvanceCounterClockwise(std::list<int>& marbles, std::list<int>::iterator& currentMarble, int advance)
	{
		for (int i = 0; i < advance; ++i)
		{
			if (currentMarble != marbles.begin())
				currentMarble--;
			else
				currentMarble = std::prev(marbles.end());
		}
	}

	uint64_t MarbleMania::GetResultOnPart1(const std::vector<std::string> input)
	{
		int numPlayers;
		int lastMarble;
		sscanf_s(input[0].c_str(), "%d players; last marble is worth %d points", &numPlayers, &lastMarble);

		std::vector<uint64_t> playerScores(numPlayers);
		std::list<int> placedMarbles = { 0 };
		auto currentMarble = placedMarbles.begin();

		int player = 1;
		for (int marble = 1; marble <= lastMarble; ++marble)
		{
			// Special case, if marble is multiple of 23:
			if (marble % 23 == 0)
			{
				// Add this marble to player's score:
				playerScores[player - 1] += marble;

				// Also add marble from 7 positions counter-clockwise:
				AdvanceCounterClockwise(placedMarbles, currentMarble, 7);
				playerScores[player - 1] += *currentMarble;

				// Remove marble and make marble immediately clockwise to it the new current marble:
				currentMarble = placedMarbles.erase(currentMarble);
			}
			else
			{
				// Find position for insert and place marble:
				AdvanceClockwise(placedMarbles, currentMarble, 2);
				currentMarble = placedMarbles.insert(currentMarble, marble);
			}			

			// next player:
			player = (player % numPlayers) + 1;	// -> maps to 1..NumOfPlayers
		}

		// Return maximum score:
		return *std::max_element(playerScores.begin(), playerScores.end());
	}
}
