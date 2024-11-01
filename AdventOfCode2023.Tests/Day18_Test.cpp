#include "stdafx.h"
#include "Day18/Day18_LavaductLagoon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day18;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day18)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"R 6 (#70c710)",
				"D 5 (#0dc571)",
				"L 2 (#5713f0)",
				"D 2 (#d2c081)",
				"R 2 (#59c680)",
				"D 2 (#411b91)",
				"L 5 (#8ceee2)",
				"U 2 (#caa173)",
				"L 1 (#1b58a2)",
				"U 2 (#caa171)",
				"R 2 (#7807d2)",
				"U 3 (#a77fa3)",
				"L 2 (#015232)",
				"U 2 (#7a21e3)"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			LavaductLagoon sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(62ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			LavaductLagoon sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(952408144115ull, result);
		};
	};

	std::vector<std::string> Year2023_Day18::inputData1;
}
