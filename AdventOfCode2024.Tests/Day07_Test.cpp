#include "stdafx.h"
#include "Day07/Day07_BridgeRepair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day07;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day07)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"190: 10 19",
				"3267: 81 40 27",
				"83: 17 5",
				"156: 15 6",
				"7290: 6 8 6 15",
				"161011: 16 10 13",
				"192: 17 8 14",
				"21037: 9 7 18 13",
				"292: 11 6 16 20"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			BridgeRepair sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3749ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			BridgeRepair sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(11387ull, result);
		};
	};
	std::vector<std::string> Year2024_Day07::inputData1;
}
