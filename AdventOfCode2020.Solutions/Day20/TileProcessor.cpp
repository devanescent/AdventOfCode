#include "TileProcessor.h"

namespace AdventOfCode::Year2020::Day20
{
	std::vector<Tile> TileProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Tile> tiles;

		int tileID = 0;
		int lineCount = 0;
		std::string top, right, bottom, left;
		bool hasTileBeenAdded = true;

		for (const std::string& line : input)
		{
			if (line.rfind("Tile", 0) == 0)
			{
				tileID = atoi(line.c_str() + 5);
				lineCount = 0;
				hasTileBeenAdded = false;
			}
			else if (!line.empty())
			{
				// edges are "read" from left to right in each direction: therefore bottom line is reverted
				if (lineCount == 0)
					top = line;
				else if (lineCount == 9)
					bottom = std::string(line.rbegin(), line.rend());
				
				// right is read from top down, left from bottom up
				right.push_back(line.back());
				left.insert(0, 1, line.front());

				++lineCount;
			}
			else if (!hasTileBeenAdded)
			{
				// add tile after empty line:
				tiles.emplace_back(tileID, top, right, bottom, left);
				hasTileBeenAdded = true;
				
				// clear manually, because these are not overwritten, only appended
				right.clear();
				left.clear();
			}
		}

		// Add last tile, if necessary:
		if (!hasTileBeenAdded)
			tiles.emplace_back(tileID, top, right, bottom, left);

		return tiles;
	}
}
