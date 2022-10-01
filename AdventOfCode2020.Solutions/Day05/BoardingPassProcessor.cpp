#include "BoardingPassProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day05
{
	std::vector<int> BoardingPassProcessor::Process(std::vector<std::string> boardingPasses)
	{
		std::vector<int> seatIDs;
		seatIDs.reserve(boardingPasses.size());

		std::transform(boardingPasses.begin(), boardingPasses.end(), std::back_inserter(seatIDs), 
			[](std::string& pass)
			{ 
				// convert to binary representation
				for (char& c : pass)
				{
					if (c == 'F' || c == 'L')      c = '0';
					else if (c == 'B' || c == 'R') c = '1';
				}

				// row: 7 digits from front
				long row = std::strtol(pass.substr(0, 7).c_str(), nullptr, 2);

				// col: 3 digits from back
				long col = std::strtol(pass.substr(pass.length() - 3).c_str(), nullptr, 2);

				// seat ID
				return row * 8 + col;
			}
		);

		return seatIDs;
	}
}