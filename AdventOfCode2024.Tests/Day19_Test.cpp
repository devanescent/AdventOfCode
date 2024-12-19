#include "stdafx.h"
#include "Day19/Day19_LinenLayout.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day19;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day19)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"r, wr, b, g, bwu, rb, gb, br",
				"",
				"brwrr",
				"bggr",
				"gbbr",
				"rrbgbr",
				"ubwu",
				"bwurrg",
				"brgr",
				"bbrgwb"
			};

			inputData2 = std::vector<std::string>
			{
				"abbc, a, bb, b, c",
				"",
				"abbc"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			LinenLayout sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			LinenLayout sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(16ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			LinenLayout sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(3ull, result);
		};
	};
	std::vector<std::string> Year2024_Day19::inputData1;
	std::vector<std::string> Year2024_Day19::inputData2;
}
