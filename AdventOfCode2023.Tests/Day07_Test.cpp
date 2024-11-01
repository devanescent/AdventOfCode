#include "stdafx.h"
#include "Day07/Day07_CamelCards.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day07;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day07)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"32T3K 765",
				"T55J5 684",
				"KK677 28",
				"KTJJT 220",
				"QQQJA 483"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CamelCards sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(6440ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			CamelCards sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(5905ull, result);
		};
	};

	std::vector<std::string> Year2023_Day07::inputData1;
}
