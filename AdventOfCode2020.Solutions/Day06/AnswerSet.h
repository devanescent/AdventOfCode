#pragma once
#include <algorithm>
#include <string>
#include <set>

namespace AdventOfCode::Year2020::Day06
{
	class AnswerSet
	{
	public:
		enum class CollectionMode
		{
			Anyone,
			Everyone
		};

		AnswerSet() {}
		AnswerSet(std::vector<std::string>&& answers) : m_answers(answers) {}

		void Add(std::string answer)
		{
			// Set operations require sorted inputs:
			std::sort(answer.begin(), answer.end());
			m_answers.emplace_back(answer);
		}

		int NumberOfUniqueAnswers(CollectionMode colMode) const
		{
			size_t answerCount = 0;

			// Collect all answers that anyone in the group answered 'yes' to
			// -> union of all answers
			if (colMode == CollectionMode::Anyone)
			{
				std::set<char> anyoneAnswered;
				for (const std::string& answers : m_answers)
					anyoneAnswered.insert(answers.begin(), answers.end());

				answerCount = anyoneAnswered.size();
			}
			// Collect all answers that everyone in the group answered 'yes' to
			// -> intersection of all answers
			else if (colMode == CollectionMode::Everyone)
			{
				// Initialitze with the first answer:
				std::set<char> everyoneAnswered(m_answers[0].begin(), m_answers[0].end());
				for (const std::string& answers : m_answers)
				{
					// Intersection of new answers with the previous ones:
					auto answersSoFar = everyoneAnswered;
					everyoneAnswered.clear();

					std::set_intersection(
						answersSoFar.begin(), answersSoFar.end(),
						answers.begin(), answers.end(),
						std::inserter(everyoneAnswered, everyoneAnswered.end())
					);
				}

				answerCount = everyoneAnswered.size();
			}

			return static_cast<int>(answerCount);
		}

		bool operator==(const AnswerSet& other) const
		{
			return m_answers == other.m_answers;
		}

		std::string ToString() const
		{
			std::string result;
			for (const std::string answer : m_answers)
			{
				if (!result.empty()) result.append("|");
				result.append(answer);
			}
				
			return result;
		}

	private:
		//std::set<char> m_answers;

		std::vector<std::string> m_answers;
	};
}

