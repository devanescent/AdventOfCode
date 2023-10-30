#pragma once
#include "Day.h"

namespace AdventOfCode::Year2017::Day09
{
	// ---------------------------------------------------------------------------
	// Day09: Stream Processing
	// ---------------------------------------------------------------------------
	class StreamProcessing : public Day<>
	{
	public:
		StreamProcessing();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> input) override;
		uint64_t ExecutePart2(std::vector<std::string> input) override;

	private:
		int ProcessGroup(std::string::const_iterator& strIt, std::string::const_iterator strEnd, int currentGrpScore, int totalScore, int& totalGarbage);
		void ProcessGarbage(std::string::const_iterator& strIt, std::string::const_iterator strEnd, int& totalGarbage);
	};
}
