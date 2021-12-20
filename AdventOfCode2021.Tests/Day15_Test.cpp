#include "stdafx.h"
#include "Day15\Day15_Chiton.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day15;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day15)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"1163751742",
				"1381373672",
				"2136511328",
				"3694931569",
				"7463417111",
				"1319128137",
				"1359912421",
				"3125421639",
				"1293138521",
				"2311944581"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			Chiton day15;

			// Act:
			uint64_t result = day15.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(40ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			Chiton day15;

			// Act:
			uint64_t result = day15.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(315ull, result);
		}
	};

	std::vector<std::string> Day15::inputData = std::vector<std::string>();
}