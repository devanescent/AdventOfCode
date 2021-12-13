#include "OrigamiProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2021::Day13
{
	std::pair<std::vector<FoldInstruction>, OrigamiPaper> OrigamiProcessor::Process(std::vector<std::string> input)
	{
		auto sepLine = std::find(input.begin(), input.end(), "");

		// Paper:
		OrigamiPaper paper;
		int xMax = 0;	// for resizing the vector structure (Origami paper) to a proper rectangle
		int yMax = 0;
		for (auto lineIt = input.begin(); lineIt != sepLine; ++lineIt)
		{
			std::istringstream iss(*lineIt);
			std::string xStr, yStr;

			std::getline(iss, xStr, ',');
			std::getline(iss, yStr, ',');

			int x = std::stoi(xStr);
			xMax = std::max(x, xMax);

			int y = std::stoi(yStr);
			yMax = std::max(y, yMax);

			// Resize vectors if necessary:
			int xSize = x + 1;
			int ySize = y + 1;
			if (paper.size() < ySize)
				paper.resize(ySize, std::vector<bool>(xSize, false));

			if (paper[y].size() < xSize)
				paper[y].resize(xSize, false);

			// Add point:
			paper[y][x] = true;
		}

		// Resize paper to rectangle:
		int xSize = xMax + 1;
		int ySize = yMax + 1;
		paper.resize(ySize, std::vector<bool>(xSize, false));
		for (int y = 0; y <= yMax; ++y)
		{
			if (paper[y].size() < xSize)
				paper[y].resize(xSize, false);
		}

		// Fold instructions:
		std::vector<FoldInstruction> foldInstrs;
		for (auto lineIt = std::next(sepLine); lineIt != input.end(); ++lineIt)
		{ 
			std::istringstream iss(*lineIt);
			std::string axis, value;

			std::getline(iss, axis, '=');
			std::getline(iss, value, '=');

			foldInstrs.emplace_back(axis.back() == 'x' ? FoldDirection::Horizontal : FoldDirection::Vertical, std::stoi(value));
		}

		return std::make_pair(foldInstrs, paper);
	}
}

