#include "stdafx.h"
#include "Day03/Day03_GearRatios.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day03;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day03)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"467..114..",
				"...*......",
				"..35..633.",
				"......#...",
				"617*......",
				".....+.58.",
				"..592.....",
				"......755.",
				"...$.*....",
				".664.598.."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			GearRatios sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(4361ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			GearRatios sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(467835ull, result);
		};
	};

	std::vector<std::string> Year2023_Day03::inputData1;
}
