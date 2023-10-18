#include "Day09_StreamProcessing.h"

namespace AdventOfCode::Year2017::Day09
{
	StreamProcessing::StreamProcessing() : Day(9, "Stream Processing") { }

	uint64_t StreamProcessing::GetResultOnPart1(std::vector<std::string> input)
	{
		const std::string& stream = input[0];
		auto streamStart = stream.cbegin();

		return ProcessGroup(streamStart, stream.cend(), 1, 0);
	}

	uint64_t StreamProcessing::GetResultOnPart2(std::vector<std::string> input)
	{
		return uint64_t();
	}

	int StreamProcessing::ProcessGroup(std::string::const_iterator& strIt, std::string::const_iterator strEnd, int currentGrpScore, int totalScore)
	{
		while (strIt != strEnd)
		{
			char currentChar = *strIt;
			++strIt;

			switch (currentChar)
			{
				case '{':
					// New group found:
					totalScore = ProcessGroup(strIt, strEnd, currentGrpScore + 1, totalScore + currentGrpScore);
					break;

				case '}':
					// Group finished:
					return totalScore;

				case '<':
					// Garbage found:
					ProcessGarbage(strIt, strEnd);
					break;
			}
		}

		return totalScore;
	}

	void StreamProcessing::ProcessGarbage(std::string::const_iterator& strIt, std::string::const_iterator strEnd)
	{
		while (strIt != strEnd)
		{
			char currentChar = *strIt;
			++strIt;

			switch (currentChar)
			{
				case '!':
					// Ignore the following character:
					++strIt;
					break;

				case '>':
					// Garbage finished:
					return;
			}
		}
	}
}
