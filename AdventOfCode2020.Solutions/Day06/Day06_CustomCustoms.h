#pragma once
#include "DayT.h"
#include "AnswerSet.h"
#include "AnswerProcessor.h"

namespace AdventOfCode::Year2020::Day06
{
	class CustomCustoms : public DayT<AnswerSet, AnswerProcessor>
	{
	public:
		CustomCustoms();

	protected:
		uint64_t ExecutePart1(std::vector<AnswerSet> answerSets) override;
	};
}