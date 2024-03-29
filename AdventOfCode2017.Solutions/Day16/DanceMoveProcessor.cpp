﻿#include "DanceMoveProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day16
{
	std::vector<std::unique_ptr<DanceMove>> DanceMoveProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::unique_ptr<DanceMove>> dance;

		std::istringstream allMoves(input[0]);
		std::string currentMove;

		while (std::getline(allMoves, currentMove, ','))
		{
			std::istringstream iss(currentMove);
			char moveType;
			iss >> moveType;

			switch (moveType)
			{
				case 's':
					int spinSize;
					iss >> spinSize;
					dance.emplace_back(std::make_unique<Spin>(spinSize));
					break;

				case 'x':
					int posA, posB;
					char separator;
					iss >> posA >> separator >> posB;
					dance.emplace_back(std::make_unique<Exchange>(posA, posB));
					break;

				case 'p':
					char prgmA, prgmB;
					iss >> prgmA >> separator >> prgmB;
					dance.emplace_back(std::make_unique<Partner>(prgmA, prgmB));
					break;
			}
		}

		return dance;
	}
}
