#pragma once

namespace AdventOfCode::Year2022::Day02
{
	// Scores:
	// Selected shape: 1 for Rock, 2 for Paper, and 3 for Scissors
	enum class HandShape
	{
		Rock = 1,
		Paper = 2,
		Scissors = 3
	};

	// Outcome of the round: 0 if you lost, 3 if the round was a draw, and 6 if you won
	enum class RoundResult
	{
		Lose = 0,
		Draw = 3,
		Win = 6
	};

	class RockPaperScissorsRound
	{
	public:
		HandShape OpponentsPick;

		// for part 1:
		HandShape YourPick;

		// for part 2:
		RoundResult RequiredResult;

		int GetScoreByOpponentsPick() const
		{
			int score = static_cast<int>(YourPick);

			if (YourPick == HandShape::Rock)
			{
				if (OpponentsPick == HandShape::Scissors)
					score += 6;
				else if (OpponentsPick == HandShape::Rock)
					score += 3;
			}
			else if (YourPick == HandShape::Paper)
			{
				if (OpponentsPick == HandShape::Rock)
					score += 6;
				else if (OpponentsPick == HandShape::Paper)
					score += 3;
			}
			else if (YourPick == HandShape::Scissors)
			{
				if (OpponentsPick == HandShape::Paper)
					score += 6;
				else if (OpponentsPick == HandShape::Scissors)
					score += 3;
			}
			return score;
		}

		int GetScoreByRequiredResult() const
		{
			int score = static_cast<int>(RequiredResult);

			if (OpponentsPick == HandShape::Rock)
			{
				if (RequiredResult == RoundResult::Lose)
					score += static_cast<int>(HandShape::Scissors);
				else if (RequiredResult == RoundResult::Draw)
					score += static_cast<int>(HandShape::Rock);
				else if (RequiredResult == RoundResult::Win)
					score += static_cast<int>(HandShape::Paper);
			}
			else if (OpponentsPick == HandShape::Paper)
			{
				if (RequiredResult == RoundResult::Lose)
					score += static_cast<int>(HandShape::Rock);
				else if (RequiredResult == RoundResult::Draw)
					score += static_cast<int>(HandShape::Paper);
				else if (RequiredResult == RoundResult::Win)
					score += static_cast<int>(HandShape::Scissors);
			}
			else if (OpponentsPick == HandShape::Scissors)
			{
				if (RequiredResult == RoundResult::Lose)
					score += static_cast<int>(HandShape::Paper);
				else if (RequiredResult == RoundResult::Draw)
					score += static_cast<int>(HandShape::Scissors);
				else if (RequiredResult == RoundResult::Win)
					score += static_cast<int>(HandShape::Rock);
			}
			return score;
		}
	};
}
