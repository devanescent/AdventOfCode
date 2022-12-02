#include "StrategyGuideProcessor.h"

namespace AdventOfCode::Year2022::Day02
{
	std::vector<RockPaperScissorsRound> StrategyGuideProcessor::Process(std::vector<std::string> input)
	{
		std::vector<RockPaperScissorsRound> rounds;

		for (const std::string& line : input)
		{
			RockPaperScissorsRound round;
			switch (line[0])
			{
				case 'A': round.OpponentsPick = HandShape::Rock; break;
				case 'B': round.OpponentsPick = HandShape::Paper; break;
				case 'C': round.OpponentsPick = HandShape::Scissors; break;
			}

			switch (line[2])
			{
				case 'X':
					round.YourPick = HandShape::Rock;
					round.RequiredResult = RoundResult::Lose;
					break;
				case 'Y':
					round.YourPick = HandShape::Paper;
					round.RequiredResult = RoundResult::Draw;
					break;
				case 'Z':
					round.YourPick = HandShape::Scissors;
					round.RequiredResult = RoundResult::Win;
					break;
			}

			rounds.emplace_back(round);
		}

		return rounds;
	}
}
