#include "stdafx.h"
#include "Day08/Day08_TreetopTreeHouse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day08;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day08)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"30373",
				"25512",
				"65332",
				"33549",
				"35390"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			TreetopTreeHouse sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(21ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			TreetopTreeHouse sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(8ull, result);
		};
	};

	std::vector<std::string> Year2022_Day08::inputData1;
}
