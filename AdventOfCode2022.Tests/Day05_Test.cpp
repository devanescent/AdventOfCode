#include "stdafx.h"
#include "Day05\Day05_SupplyStacks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day05;
using namespace std::string_literals;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day05)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"    [D]    ",
				"[N] [C]    ",
				"[Z] [M] [P]",
				" 1   2   3 ",
				"",
				"move 1 from 2 to 1",
				"move 3 from 1 to 3",
				"move 2 from 2 to 1",
				"move 1 from 1 to 2"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			SupplyStacks sut;
			// Act:
			std::string result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual("CMZ"s, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			SupplyStacks sut;
			// Act:
			std::string result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual("MCD"s, result);
		};

	};
	std::vector<std::string> Year2022_Day05::inputData1 = std::vector<std::string>();
}
