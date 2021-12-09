#include "TileProcessor.h"

namespace AdventOfCode::Year2020::Day20
{
	std::vector<Tile> TileProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Tile> tiles;
		int tileID = 0;
		int lineCount = 0;
		std::string top, right, bottom, left;

		for (const std::string& line : input)
		{
			if (line.substr(0, 4).compare("Tile") == 0)
			{
				tileID = atoi(line.c_str() + 5);
				lineCount = 0;
			}
			else if (!line.empty())
			{
				// edges are "read" from left to right in each direction: therefore bottom line is reverted, 
				if (lineCount == 0)
					top = line;
				else if (lineCount == 9)
				{
					bottom = line;
					std::reverse(bottom.begin(), bottom.end());
				}
				
				// right is read from top down, left from bottom up
				right.push_back(line.back());
				left.insert(0, 1, line.front());

				++lineCount;
			}
			else
			{
				// add tile:
				tiles.push_back(Tile(tileID, top, right, bottom, left));
				right.clear();	// clear manually, because these are not overwritten, only appended
				left.clear();
			}
		}

		// last tile:
		tiles.push_back(Tile(tileID, top, right, bottom, left));
		return tiles;
	}
}
