#include "stdafx.h"
#include "Day19\Day19_NotEnoughMinerals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day19;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day19)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Blueprint 1: Each ore robot costs 4 ore. Each clay robot costs 2 ore. Each obsidian robot costs 3 ore and 14 clay. Each geode robot costs 2 ore and 7 obsidian.",
				"Blueprint 2: Each ore robot costs 2 ore. Each clay robot costs 3 ore. Each obsidian robot costs 3 ore and 8 clay. Each geode robot costs 3 ore and 12 obsidian."
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			NotEnoughMinerals sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(33ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			NotEnoughMinerals sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual((uint64_t)(56 * 62), result);
		};

	};
	std::vector<std::string> Year2022_Day19::inputData1 = std::vector<std::string>();
}
