#include "stdafx.h"
#include "Day01/Day01_HistorianHysteria.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day01;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day01)
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
				"3   4",
				"4   3",
				"2   5",
				"1   3",
				"3   9",
				"3   3"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HistorianHysteria sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(11ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HistorianHysteria sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(31ull, result);
		};
	};

	std::vector<std::string> Year2024_Day01::inputData1;
}
