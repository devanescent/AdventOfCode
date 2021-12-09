#include "Day05_BinaryBoarding.h"
#include <algorithm>
#include <cmath>

namespace AdventOfCode::Year2020::Day05
{
	BinaryBoarding::BinaryBoarding(int rowNum, int colNum) : Day(5, "Binary Boarding"), 
		m_rowNum(rowNum), m_colNum(colNum)
	{}

	uint64_t BinaryBoarding::GetResultOnPart1(std::vector<std::string> input)
	{
		if (input.empty())
			return 0;

		// find seat ID for each boarding pass
		std::vector<int> seatIDs;
		seatIDs.reserve(input.size());
		std::transform(input.begin(), input.end(), std::back_inserter(seatIDs), [&](std::string pass) { return GetSeatID(pass); });

		// return maximum of all ids
		return *(std::max_element(seatIDs.begin(), seatIDs.end()));
	}

	int BinaryBoarding::GetSeatID(std::string seatPartioning)
	{
		// convert to binary representation
		std::replace(seatPartioning.begin(), seatPartioning.end(), 'F', '0');
		std::replace(seatPartioning.begin(), seatPartioning.end(), 'B', '1');
		std::replace(seatPartioning.begin(), seatPartioning.end(), 'L', '0');
		std::replace(seatPartioning.begin(), seatPartioning.end(), 'R', '1');

		// row: logb(rowNum) digits from front
		long row = std::strtol(seatPartioning.substr(0, (int)std::logb(m_rowNum)).c_str(), nullptr, 2);

		// col: logb(colNum) digits from back
		long col = std::strtol(seatPartioning.substr(seatPartioning.size() - (int)std::logb(m_colNum)).c_str(), nullptr, 2);

		// seat ID
		return row * 8 + col;
	}
}
