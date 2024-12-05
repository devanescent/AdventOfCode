#include "stdafx.h"
#include "Day05/Day05_PrintQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day05;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day05)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"47|53",
				"97|13",
				"97|61",
				"97|47",
				"75|29",
				"61|13",
				"75|53",
				"29|13",
				"97|29",
				"53|29",
				"61|53",
				"97|53",
				"61|29",
				"47|13",
				"75|47",
				"97|75",
				"47|61",
				"75|61",
				"47|29",
				"75|13",
				"53|13",
				"",
				"75,47,61,53,29",
				"97,61,53,29,13",
				"75,29,13",
				"75,97,47,61,53",
				"61,13,29",
				"97,13,75,29,47"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PrintQueue sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(143ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PrintQueue sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(123ull, result);
		};
	};
	std::vector<std::string> Year2024_Day05::inputData1;
}
