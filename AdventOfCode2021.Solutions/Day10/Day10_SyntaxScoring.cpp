#include "Day10_SyntaxScoring.h"
#include <stack>
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2021::Day10
{
	SyntaxScoring::SyntaxScoring() : Day(10, "Syntax Scoring") {}

	uint64_t SyntaxScoring::GetResultOnPart1(const std::vector<std::string> input)
	{
		return std::accumulate(input.begin(), input.end(), 0ull,
			[](uint64_t corruptionScore, const std::string& chunkLine)
			{
				return corruptionScore + GetScore(chunkLine).first; // corruption score
			}
		);
	}

	uint64_t SyntaxScoring::GetResultOnPart2(const std::vector<std::string> input)
	{
		std::vector<uint64_t> incompleteScores;
		incompleteScores.reserve(input.size());

		std::transform(input.begin(), input.end(), std::back_inserter(incompleteScores), 
			[](const std::string& line)
			{
				return GetScore(line).second; // score for incomplete lines
			}
		);

		// Remove corrupted lines:
		incompleteScores.erase(std::remove(incompleteScores.begin(), incompleteScores.end(), 0ull), incompleteScores.end());

		// return middle element:
		int middleElem = static_cast<int>(incompleteScores.size()) / 2;
		std::nth_element(incompleteScores.begin(), incompleteScores.begin() + middleElem, incompleteScores.end());
		return incompleteScores[middleElem];
	}


	std::pair<uint64_t, uint64_t> GetScore(const std::string& chunkLine)
	{
		std::stack<char> bracketStack; // stack for testing matching bracket pairs
		for (char c : chunkLine)
		{
			switch (c)
			{
				// Opening brackets: push to stack
				case '(': case '[': case '{': case '<':
					bracketStack.push(c);
					break;

				// For closing brackets:
				// Compare to last bracket on stack: if it does not match, the line is corrupted
				case ')':
				{
					if (bracketStack.top() == '(')
						bracketStack.pop();
					else
						return std::make_pair(3, 0); // Corrupted line with unexpected ')'
					break;
				}
				case ']':
				{
					if (bracketStack.top() == '[')
						bracketStack.pop();
					else
						return std::make_pair(57, 0); // Corrupted line with unexpected ']'
					break;
				}
				case '}':
				{
					if (bracketStack.top() == '{')
						bracketStack.pop();
					else
						return std::make_pair(1197, 0); // Corrupted line with unexpected '}'
					break;
				}
				case '>':
				{
					if (bracketStack.top() == '<')
						bracketStack.pop();
					else
						return std::make_pair(25137, 0); // Corrupted line with unexpected '>'
					break;
				}
				default:
					break;
			}
		}

		// Not corrupted, but still opening brackets remaining: line is incomplete
		uint64_t score = 0;
		while (!bracketStack.empty())
		{
			// Score: Multiply by 5 and add the following scores for each opening bracket remaining in the stack:
			score *= 5;
			switch (bracketStack.top())
			{
				case '(':
					score += 1;
					break;
				case '[':
					score += 2;
					break;
				case '{':
					score += 3;
					break;
				case '<':
					score += 4;
					break;
			}

			bracketStack.pop();
		}

		return std::make_pair(0, score);
	}
}


