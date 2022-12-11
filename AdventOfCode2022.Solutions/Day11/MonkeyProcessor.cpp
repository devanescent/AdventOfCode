#include "MonkeyProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2022::Day11
{
	std::vector<Monkey> MonkeyProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Monkey> monkeys;

		auto lineIt = input.begin();

		while (lineIt != input.end())
		{
			// Blank line separating monkeys
			if (lineIt->empty())
				++lineIt;

			Monkey monkey;
			++lineIt;

			SetStartingItems(*lineIt, monkey);
			++lineIt;

			SetOperation(*lineIt, monkey);
			++lineIt;

			SetTest(*lineIt, monkey);
			++lineIt;

			SetTarget(*lineIt, monkey);
			++lineIt;
			SetTarget(*lineIt, monkey);
			++lineIt;

			monkeys.emplace_back(monkey);
		}

		return monkeys;
	}

	void MonkeyProcessor::SetStartingItems(const std::string& line, Monkey& monkey)
	{
		//   Starting items: X, Y, ...
		std::istringstream iss(line);
		std::string str;
		iss >> str >> str; // ignore text "Starting items:"

		while (std::getline(iss, str, ','))
			monkey.Items.emplace(std::stoi(str));
	}

	void MonkeyProcessor::SetOperation(const std::string& line, Monkey& monkey)
	{
		//   Operation: new = A op B
		std::istringstream iss(line);
		std::string str;
		
		iss >> str >> str >> str // ignore text "Operation: new = "
			>> monkey.InspectLhs >> monkey.InspectOp >> monkey.InspectRhs;
	}

	void MonkeyProcessor::SetTest(const std::string& line, Monkey& monkey)
	{
		//   Test: divisible by P
		std::istringstream iss(line);
		std::string str;

		iss >> str >> str >> str >> monkey.TestDivisor; // ignore "Test: divisible by"
	}

	void MonkeyProcessor::SetTarget(const std::string& line, Monkey& monkey)
	{
		// If true: throw to monkey X
		// If false: throw to monkey Y
		std::istringstream iss(line);
		std::string str;
		iss >> str >> str;

		if (str == "true:")
			iss >> str >> str >> str >> monkey.TargetOnTestTrue; // ignore "throw to monkey"
		else
			iss >> str >> str >> str >> monkey.TargetOnTestFalse; // ignore "throw to monkey"
	}
}
