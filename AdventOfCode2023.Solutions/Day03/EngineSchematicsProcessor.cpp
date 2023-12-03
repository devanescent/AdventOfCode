#include "EngineSchematicsProcessor.h"

namespace AdventOfCode::Year2023::Day03
{
	std::vector<PartNumber> EngineSchematicsProcessor::Process(std::vector<std::string> input)
	{
		std::vector<PartNumber> partNumbers;
		int currentPartNumber = 0;

		int lineNumber = 0;
		for (const std::string& line : input)
		{
			int lineOffset = 0;
			while (lineOffset < line.length())
			{
				const char c = line[lineOffset];
				if (c >= '0' && c <= '9')
				{
					// Found a potential part number
					currentPartNumber = std::stoi(line.substr(lineOffset));
					while (lineOffset < line.length() && line[lineOffset] >= '0' && line[lineOffset] <= '9')
					{
						Point<int> currentPos(lineOffset, lineNumber);
						bool foundPartNumber = false;
						for (auto&& adjPoint : currentPos.GetSurroundingPoints(true))
						{
							if (adjPoint.X >= 0 && adjPoint.X < line.length() && adjPoint.Y >= 0 && adjPoint.Y < input.size())
							{
								// Point is inside the schematics:
								char adj = input[adjPoint.Y][adjPoint.X];
								if (adj != '.' && (adj < '0' || adj > '9'))
								{
									// Found a symbol: current number is indeed a part number
									partNumbers.emplace_back(currentPartNumber, adj, adjPoint);
									foundPartNumber = true;
									break;
								}
							}
						}

						// If part number was found, skip to the end of the current number:
						if (foundPartNumber)
						{
							while (lineOffset < line.length() && line[lineOffset] >= '0' && line[lineOffset] <= '9')
								++lineOffset;
							continue;
						}
						else
							++lineOffset;
					}
				}

				++lineOffset;
			}

			++lineNumber;
		}


		return partNumbers;
	}
}
