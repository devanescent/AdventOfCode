#include "stdafx.h"
#include "Day11\Day11_MonkeyintheMiddle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day11;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day11)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Monkey 0:",
				"  Starting items: 79, 98",
				"  Operation: new = old * 19",
				"  Test: divisible by 23",
				"    If true: throw to monkey 2",
				"    If false: throw to monkey 3",
				"",
				"Monkey 1:",
				"  Starting items: 54, 65, 75, 74",
				"  Operation: new = old + 6",
				"  Test: divisible by 19",
				"    If true: throw to monkey 2",
				"    If false: throw to monkey 0",
				"",
				"Monkey 2:",
				"  Starting items: 79, 60, 97",
				"  Operation: new = old * old",
				"  Test: divisible by 13",
				"    If true: throw to monkey 1",
				"    If false: throw to monkey 3",
				"",
				"Monkey 3:",
				"  Starting items: 74",
				"  Operation: new = old + 3",
				"  Test: divisible by 17",
				"    If true: throw to monkey 0",
				"    If false: throw to monkey 1"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MonkeyInTheMiddle sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(10605ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			MonkeyInTheMiddle sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(2713310158ull, result);
		};

	};
	std::vector<std::string> Year2022_Day11::inputData1 = std::vector<std::string>();
}
