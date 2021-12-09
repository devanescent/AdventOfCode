#include "Day06_CustomCustoms.h"
#include <numeric>

namespace AdventOfCode::Year2020::Day06
{
	CustomCustoms::CustomCustoms() : DayT(6, "Custom Customs") {}

	uint64_t Day06::CustomCustoms::ExecutePart1(std::vector<AnswerSet> answerSets)
	{
		if (answerSets.empty())
			return 0;

		// sum unique answers count all answer sets:
		return std::accumulate(answerSets.begin(), answerSets.end(), 0, 
			[](const int& res, const AnswerSet& a) 
			{ 
				return res + a.NumberOfUniqueAnswers(); 
			}
		);
	}
}

