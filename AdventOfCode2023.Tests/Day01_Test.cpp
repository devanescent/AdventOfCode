#include "stdafx.h"
#include "Day01\Day01_Trebuchet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day01;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day01)
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
				"1abc2",
				"pqr3stu8vwx",
				"a1b2c3d4e5f",
				"treb7uchet"
			};

			inputData2 = std::vector<std::string>
			{
				"two1nine",
				"eightwothree",
				"abcone2threexyz",
				"xtwone3four",
				"4nineeightseven2",
				"zoneight234",
				"7pqrstsixteen"
			};

			inputData3 = std::vector<std::string>
			{
				"abc9abc",
			};
		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Trebuchet sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(142ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			Trebuchet sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(281ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			Trebuchet sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(99ull, result);
		};
	};
	std::vector<std::string> Year2023_Day01::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2023_Day01::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2023_Day01::inputData3 = std::vector<std::string>();
}
