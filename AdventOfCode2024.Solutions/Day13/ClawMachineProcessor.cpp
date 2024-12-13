#include "ClawMachineProcessor.h"
#include <regex>

namespace AdventOfCode::Year2024::Day13
{
	std::vector<ClawMachine> ClawMachineProcessor::Process(std::vector<std::string> input)
	{
		std::regex buttonA(R"(Button A\: X\+(\d+), Y\+(\d+))");
		std::regex buttonB(R"(Button B\: X\+(\d+), Y\+(\d+))");
		std::regex prize(R"(Prize\: X\=(\d+), Y\=(\d+))");

		std::smatch matches;

		std::vector<ClawMachine> clawMachines;

		auto lineIt = input.begin();
		while (lineIt != input.end())
		{
			if (lineIt->empty())
				++lineIt;

			ClawMachine machine;

			std::regex_search(*lineIt, matches, buttonA);
			machine.ButtonA.X = std::stoi(matches[1].str());
			machine.ButtonA.Y = std::stoi(matches[2].str());
			++lineIt;

			std::regex_search(*lineIt, matches, buttonB);
			machine.ButtonB.X = std::stoi(matches[1].str());
			machine.ButtonB.Y = std::stoi(matches[2].str());
			++lineIt;

			std::regex_search(*lineIt, matches, prize);
			machine.Prize.X = std::stoi(matches[1].str());
			machine.Prize.Y = std::stoi(matches[2].str());
			++lineIt;

			clawMachines.emplace_back(machine);
		}

		return clawMachines;
	}
}
