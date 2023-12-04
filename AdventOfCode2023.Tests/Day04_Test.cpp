#include "stdafx.h"
#include "Day04\Day04_Scratchcards.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day04;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day04)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
				"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
				"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
				"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
				"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
				"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Scratchcards sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(13ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			Scratchcards sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(30ull, result);
		};
	};
	std::vector<std::string> Year2023_Day04::inputData1 = std::vector<std::string>();
}
