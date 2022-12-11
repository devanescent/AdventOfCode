#pragma once
#include "InputProcessor.h"
#include "Monkey.h"

namespace AdventOfCode::Year2022::Day11
{
	class MonkeyProcessor : public InputProcessorBase<Monkey>
	{
	public:
		std::vector<Monkey> Process(std::vector<std::string> input) override;

	private:
		void SetStartingItems(const std::string& line, Monkey& monkey);
		void SetOperation(const std::string& line, Monkey& monkey);
		void SetTest(const std::string& line, Monkey& monkey);
		void SetTarget(const std::string& line, Monkey& monkey);
	};
}
