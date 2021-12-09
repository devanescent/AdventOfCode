#include "HexProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day24
{
	std::vector<HexCoords> HexProcessor::Process(std::vector<std::string> input)
	{
		std::vector<HexCoords> coords;
		std::transform(input.begin(), input.end(), std::back_inserter(coords), [&](const std::string& directions) { return ParseDirections(directions); });
		return coords;
	}

	HexCoords HexProcessor::ParseDirections(const std::string& directions)
	{
		bool isDiag = false;		// for direction consisting of two letters (ne, nw, se, sw)
		bool isNorth;
		int swne = 0;
		int nwse = 0;

		for (char c : directions)
		{
			if (c == 'e')
			{
				// Can be standalone direction E ...
				if (!isDiag)
				{
					// E on the hex grid is equal to NE + SE
					++swne;
					++nwse;
				}
				// ...  or part of NE / SE
				else
				{
					if (isNorth)
						++swne;	// NE
					else
						++nwse;	// SE

					// reset for next direction
					isDiag = false;
				}
			}
			else if (c == 'w')
			{
				// Can be standalone direction W ...
				if (!isDiag)
				{
					// W on the hex grid is equal to NW + SW
					--swne;
					--nwse;
				}
				// ... or part of NW / SW
				else
				{
					if (isNorth)
						--nwse;	// NW
					else
						--swne;	// SW

					// reset for next direction
					isDiag = false;
				}
			}
			else if (c == 'n')
			{
				isDiag = true;
				isNorth = true;
			}
			else if (c == 's')
			{
				isDiag = true;
				isNorth = false;
			}
		}

		return HexCoords(swne, nwse);
	}
}
