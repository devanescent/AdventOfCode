#include "AnswerProcessor.h"

namespace AdventOfCode::Year2020::Day06
{
	std::vector<AnswerSet> AnswerProcessor::Process(std::vector<std::string> input)
	{
		std::vector<AnswerSet> answerSets;

		AnswerSet answerSet;
		for (const std::string& answers : input)
		{
			// Empty lines separate groups:
			if (!answers.empty())
				answerSet.Add(answers);
			else
			{
				answerSets.emplace_back(answerSet);
				answerSet = AnswerSet();
			}
		}

		// Last one:
		answerSets.emplace_back(answerSet);

		return answerSets;
	}
}