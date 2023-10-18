#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Stream Processing
	// ---------------------------------------------------------------------------
	class StreamProcessing : public Day
	{
	public:
		StreamProcessing();

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(std::vector<std::string> input) override;

	private:
		int ProcessGroup(std::string::const_iterator& strIt, std::string::const_iterator strEnd, int currentGrpScore, int totalScore);
		void ProcessGarbage(std::string::const_iterator& strIt, std::string::const_iterator strEnd);
	};
}
