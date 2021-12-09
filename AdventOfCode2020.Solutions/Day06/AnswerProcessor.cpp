#include "AnswerProcessor.h"

namespace AdventOfCode::Year2020::Day06
{
	std::vector<AnswerSet> AnswerProcessor::Process(std::vector<std::string> input)
	{
		std::vector<AnswerSet> answerSets;

		for (std::string answers : JoinLines(input))
			answerSets.push_back(AnswerSet(answers));

		return answerSets;
	}
}