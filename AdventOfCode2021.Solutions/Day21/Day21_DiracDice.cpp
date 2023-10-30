#include "Day21_DiracDice.h"
#include <map>
#include <algorithm>

namespace AdventOfCode::Year2021::Day21
{
	DiracDice::DiracDice() : Day(21, "Dirac Dice") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t DiracDice::ExecutePart1(const std::vector<std::string> input)
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

	class GameState
	{
	public:
		GameState(int player1Start, int player2Start) : Player1Start(player1Start), Player2Start(player2Start) {}

		int Player1Start;
		int Player2Start;

		int Player1Score = 0;
		int Player2Score = 0;

		bool HasPlayer1Won = false;
		bool HasPlayer2Won = false;

		void ApplyDiceRoll(int player, int roll)
		{
			if (player == 1)
			{
				Player1Start = (Player1Start + roll - 1) % 10 + 1;
				Player1Score += Player1Start;
				HasPlayer1Won = Player1Score >= 21;
			}
			else if (player == 2)
			{
				Player2Start = (Player2Start + roll - 1) % 10 + 1;
				Player2Score += Player2Start;
				HasPlayer2Won = Player2Score >= 21;
			}
		}

		bool operator==(const GameState& other) const
		{
			return
				Player1Start == other.Player1Start && Player1Score == other.Player1Score &&
				Player2Start == other.Player2Start && Player2Score == other.Player2Score;
		}
	};


	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t DiracDice::ExecutePart2(const std::vector<std::string> input)
	{
		int player1Start = 0, player2Start = 0;
		sscanf_s(input[0].c_str(), "Player 1 starting position: %d", &player1Start);
		sscanf_s(input[1].c_str(), "Player 2 starting position: %d", &player2Start);

		// Currently evaluated game states and in how many universes they occured :
		std::vector<std::pair<GameState, uint64_t>> gameStates;

		// Initial state:
		gameStates.emplace_back(GameState(player1Start, player2Start), 1ull);

		int currentPlayer = 1; // tracks who's turn it is
		uint64_t player1Wins = 0ull, player2Wins = 0ull; // how many times each player has won

		// At each turn there are 7 possible dice sums (in total, each state diverges into 27 new universes)
		// DiceRoll 3 (1x), Diceroll 4 (3x), Diceroll 5 (6x), Diceroll 6 (7x), Diceroll 7 (6x), Diceroll 8 (3x), Diceroll 9 (1x)
		const std::map<int, int> multiplyFactor{ { 3,1 },{ 4,3 },{ 5,6 },{ 6,7 },{ 7,6 },{ 8,3 },{ 9,1 } };

		while (!gameStates.empty())
		{
			std::vector<std::pair<GameState, uint64_t>> nextStates;

			for (const auto& state : gameStates)
			{
				// Calculate the new states for each of these:
				for (int diceRoll = 3; diceRoll <= 9; ++diceRoll)
				{
					// Make a copy of this state to find out, after the dice roll, how many universes with this game state there are :
					GameState nextState = state.first;
					uint64_t nextStateOccurance = state.second * multiplyFactor.at(diceRoll);

					// Evaluate the game:
					nextState.ApplyDiceRoll(currentPlayer, diceRoll);

					// Check if a player has won:
					if (nextState.HasPlayer1Won)
					{
						// Game is finished, do not track further:
						player1Wins += nextStateOccurance;
					}
					else if (nextState.HasPlayer2Won)
					{
						// Game is finished, do not track further:
						player2Wins += nextStateOccurance;
					}
					else
					{
						// Continue evaluating this game:
						nextStates.emplace_back(nextState, nextStateOccurance);
					}
				}
			}

			gameStates = std::move(nextStates);

			// Swap players:
			currentPlayer = currentPlayer % 2 + 1;
		}

		return std::max(player1Wins, player2Wins);
	}
}

