#include "Day10_SyntaxScoring.h"
#include <stack>
#include <numeric>

namespace AdventOfCode::Year2021::Day10
{
	SyntaxScoring::SyntaxScoring() : Day(10, "Syntax Scoring") {}

	uint64_t SyntaxScoring::GetResultOnPart1(const std::vector<std::string> input)
	{
		return std::accumulate(input.begin(), input.end(), 0ull,
			[](uint64_t corruptionScore, const std::string& chunkLine)
			{
				return corruptionScore + GetCorruptionScore(chunkLine);
			}
		);
	}


	uint64_t GetCorruptionScore(const std::string& chunkLine)
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
					return 3;
				break;
			}
			case ']':
			{
				if (bracketStack.top() == '[')
					bracketStack.pop();
				else
					return 57;
				break;
			}
			case '}':
			{
				if (bracketStack.top() == '{')
					bracketStack.pop();
				else
					return 1197;
				break;
			}
			case '>':
			{
				if (bracketStack.top() == '<')
					bracketStack.pop();
				else
					return 25137;
				break;
			}
			default:
				break;
			}
		}

		return 0ull;
	}
}


