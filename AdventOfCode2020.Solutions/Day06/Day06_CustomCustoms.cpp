#include "Day06_CustomCustoms.h"
#include <numeric>

namespace AdventOfCode::Year2020::Day06
{
	CustomCustoms::CustomCustoms() : DayT(6, "Custom Customs") {}

	uint64_t Day06::CustomCustoms::ExecutePart1(std::vector<AnswerSet> answerSets)
	{
		return std::accumulate(answerSets.begin(), answerSets.end(), 0, 
			[](const int& res, const AnswerSet& a) 
			{ 
				return res + a.NumberOfUniqueAnswers(AnswerSet::CollectionMode::Anyone); 
			}
		);
	}

	uint64_t Day06::CustomCustoms::ExecutePart2(std::vector<AnswerSet> answerSets)
	{
		return std::accumulate(answerSets.begin(), answerSets.end(), 0,
			[](const int& res, const AnswerSet& a)
			{
				return res + a.NumberOfUniqueAnswers(AnswerSet::CollectionMode::Everyone);
			}
		);
	}
}