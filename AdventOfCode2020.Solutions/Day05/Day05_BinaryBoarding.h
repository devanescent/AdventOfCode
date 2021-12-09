#pragma once
#include "Day.h"

namespace AdventOfCode::Year2020::Day05
{
	class BinaryBoarding : public Day
	{
	public:
		BinaryBoarding(int rowNum, int colNum);

		uint64_t GetResultOnPart1(std::vector<std::string> input) override;

	private:
		int m_rowNum;
		int m_colNum;

		int GetSeatID(std::string seatPartioning);
	};
}