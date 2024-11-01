#include "stdafx.h"
#include "Day08/Day08_HauntedWasteland.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day08;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day08)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"RL",
				"",
				"AAA = (BBB, CCC)",
				"BBB = (DDD, EEE)",
				"CCC = (ZZZ, GGG)",
				"DDD = (DDD, DDD)",
				"EEE = (EEE, EEE)",
				"GGG = (GGG, GGG)",
				"ZZZ = (ZZZ, ZZZ)"
			};

			inputData2 = std::vector<std::string>
			{
				"LLR",
				"",
				"AAA = (BBB, BBB)",
				"BBB = (AAA, ZZZ)",
				"ZZZ = (ZZZ, ZZZ)"
			};

			inputData3 = std::vector<std::string>
			{
				"LR",
				"",
				"11A = (11B, XXX)",
				"11B = (XXX, 11Z)",
				"11Z = (11B, XXX)",
				"22A = (22B, XXX)",
				"22B = (22C, 22C)",
				"22C = (22Z, 22Z)",
				"22Z = (22B, 22B)",
				"XXX = (XXX, XXX)"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HauntedWasteland sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HauntedWasteland sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HauntedWasteland sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(6ull, result);
		};
	};

	std::vector<std::string> Year2023_Day08::inputData1;
	std::vector<std::string> Year2023_Day08::inputData2;
	std::vector<std::string> Year2023_Day08::inputData3;
}
