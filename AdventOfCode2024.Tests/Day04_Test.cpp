#include "stdafx.h"
#include "Day04/Day04_CeresSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day04;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day04)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"MMMSXXMASM",
				"MSAMXMSMSA",
				"AMXSXMAAMM",
				"MSAMASMSMX",
				"XMASAMXAMM",
				"XXAMMXXAMA",
				"SMSMSASXSS",
				"SAXAMASAAA",
				"MAMMMXMMMM",
				"MXMXAXMASX"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CeresSearch sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(18ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			CeresSearch sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(9ull, result);
		};
	};
	std::vector<std::string> Year2024_Day04::inputData1;
}
