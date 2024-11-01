#include "stdafx.h"
#include "Day18/Day18_BoilingBoulders.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day18;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day18)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1,1,1",
				"2,1,1"
			};

			inputData2 = std::vector<std::string>
			{
				"2,2,2",
				"1,2,2",
				"3,2,2",
				"2,1,2",
				"2,3,2",
				"2,2,1",
				"2,2,3",
				"2,2,4",
				"2,2,6",
				"1,2,5",
				"3,2,5",
				"2,1,5",
				"2,3,5"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			BoilingBoulders sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(10ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			BoilingBoulders sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(64ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			BoilingBoulders sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(58ull, result);
		};
	};

	std::vector<std::string> Year2022_Day18::inputData1;
	std::vector<std::string> Year2022_Day18::inputData2;
}
