#include "Day02_RockPaperScissors.h"
#include <numeric>

namespace AdventOfCode::Year2022::Day02
{
	RockPaperScissors::RockPaperScissors() : DayT(02, "Rock Paper Scissors") { }

	uint64_t RockPaperScissors::ExecutePart1(std::vector<RockPaperScissorsRound> rounds)
	{
		return std::accumulate(rounds.begin(), rounds.end(), 0ull,
			[](uint64_t totalScore, const RockPaperScissorsRound& round)
			{
				return totalScore + round.GetScoreByOpponentsPick();
			}
		);
	}

	uint64_t RockPaperScissors::ExecutePart2(std::vector<RockPaperScissorsRound> rounds)
	{
		return std::accumulate(rounds.begin(), rounds.end(), 0ull,
			[](uint64_t totalScore, const RockPaperScissorsRound& round)
			{
				return totalScore + round.GetScoreByRequiredResult();
			}
		);
	}
}
