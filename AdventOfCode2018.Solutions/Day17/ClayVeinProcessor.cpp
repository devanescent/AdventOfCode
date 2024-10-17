#include "ClayVeinProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2018::Day17
{
	std::vector<ClayVein> ClayVeinProcessor::Process(std::vector<std::string> input)
	{
		std::vector<ClayVein> veins;

		for (const std::string& line : input)
		{
			/*if (std::regex_search(line, matches, horizontalVeinPattern) && matches.size() == 4)
			{
				int x1 = atoi(matches[1].str().c_str());
				int x2 = atoi(matches[2].str().c_str());
				int y = atoi(matches[3].str().c_str());

				veins.emplace_back(x1, x2, y, y);
			}
			else if (std::regex_search(line, matches, verticalVeinPattern) && matches.size() == 4)
			{
				int x = atoi(matches[1].str().c_str());
				int y1 = atoi(matches[2].str().c_str());
				int y2 = atoi(matches[3].str().c_str());

				veins.emplace_back(x, x, y1, y2);
			}*/

			std::istringstream iss(line);

			// Format: [x|y]={d}, [x|y]={d}..{d}
			char firstAxis, secondAxis;
			int firstCoord, coordRangeStart, coordRangeEnd;
			char dump;
			
			iss 
				>> firstAxis >> dump >> firstCoord // x|y={d}
				>> dump // ,
				>> secondAxis >> dump >> coordRangeStart >> dump >> dump >> coordRangeEnd; // x|y={d}..{d}

			if (firstAxis == 'x')
				veins.emplace_back(firstCoord,firstCoord, coordRangeStart, coordRangeEnd);
			else
				veins.emplace_back(coordRangeStart, coordRangeEnd, firstCoord, firstCoord);
		}

		return veins;
	}
}
