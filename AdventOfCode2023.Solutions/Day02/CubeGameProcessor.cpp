#include "CubeGameProcessor.h"
#include <regex>
#include <sstream>

namespace AdventOfCode::Year2023::Day02
{
	std::vector<GameRecord> CubeGameProcessor::Process(std::vector<std::string> input)
	{
		std::vector<GameRecord> gameRecords;

		std::regex redPattern("([0-9]+) red");
		std::regex bluePattern("([0-9]+) blue");
		std::regex greenPattern("([0-9]+) green");
		std::smatch matches;

		for (const std::string& line : input)
		{
			GameRecord record;
			record.GameNo = std::stoi(line.substr(5)); // after "Game "

			std::istringstream iss(line.substr(line.find(':') + 1)); // after ":"
			std::string cubeSet;
			while (std::getline(iss, cubeSet, ';'))
			{
				int red = 0, blue = 0, green = 0;
				if (std::regex_search(cubeSet, matches, redPattern) > 0)
					red = std::stoi(matches[1].str());
				if (std::regex_search(cubeSet, matches, bluePattern) > 0)
					blue = std::stoi(matches[1].str());
				if (std::regex_search(cubeSet, matches, greenPattern) > 0)
					green = std::stoi(matches[1].str());

				record.CubeSets.emplace_back(red, blue, green);
			}

			gameRecords.emplace_back(record);
		}

		return gameRecords;
	}
}
