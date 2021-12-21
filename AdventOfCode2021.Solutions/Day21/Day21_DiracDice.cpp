#include "Day21_DiracDice.h"

namespace AdventOfCode::Year2021::Day21
{
	DiracDice::DiracDice() : Day(21, "Dirac Dice") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t DiracDice::GetResultOnPart1(const std::vector<std::string> input)
	{
		int player1Start = 0, player2Start = 0;
		sscanf_s(input[0].c_str(), "Player 1 starting position: %d", &player1Start);
		sscanf_s(input[1].c_str(), "Player 2 starting position: %d", &player2Start);

		int diceRoll = 1;

		uint64_t numberOfDiceRolls = 0;
		uint64_t player1Score = 0, player2Score = 0;

		bool isPlayer1Turn = true;
		while (player1Score < 1000 && player2Score < 1000)
		{
			int playerRoll = 0;
			for (int r = 0; r < 3; ++r)
			{
				playerRoll += diceRoll;
				diceRoll = diceRoll % 100 + 1;
				++numberOfDiceRolls;
			}

			if (isPlayer1Turn)
			{
				player1Start = (player1Start + playerRoll - 1) % 10 + 1;
				player1Score += player1Start;
			}
			else
			{
				player2Start = (player2Start + playerRoll - 1) % 10 + 1;
				player2Score += player2Start;
			}
			
			isPlayer1Turn = !isPlayer1Turn;
		}

		// Game finished:
		if (player1Score >= 1000)
		{
			// Player 1 won
			return player2Score * numberOfDiceRolls;
		}
		else if (player2Score >= 1000)
		{
			// Player 2 won
			return player1Score * numberOfDiceRolls;
		}
		else
			return 0ull;
	}
}

