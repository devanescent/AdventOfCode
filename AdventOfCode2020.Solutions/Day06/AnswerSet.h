#pragma once
#include <string>
#include <set>

namespace AdventOfCode::Year2020::Day06
{
	class AnswerSet
	{
	public:
		AnswerSet(std::string answerSet)
		{
			// registers each answer only once
			for (char answer : answerSet)
				m_answers.insert(answer);
		}

		int NumberOfUniqueAnswers() const { return m_answers.size(); }

		bool operator==(const AnswerSet& other) const = default;

		std::string ToString() const
		{
			std::string answers;
			for (char answer : m_answers)
				answers += answer;
			return answers;
		}

	private:
		std::set<char> m_answers;
	};
}

