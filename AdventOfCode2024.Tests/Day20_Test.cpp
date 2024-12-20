#include "stdafx.h"
#include "Day20/Day20_RaceCondition.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day20;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day20)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"###############",
				"#...#...#.....#",
				"#.#.#.#.#.###.#",
				"#S#...#.#.#...#",
				"#######.#.#.###",
				"#######.#.#...#",
				"#######.#.###.#",
				"###..E#...#...#",
				"###.#######.###",
				"#...###...#...#",
				"#.#####.#.###.#",
				"#.#...#.#.#...#",
				"#.#.#.#.#.#.###",
				"#...#...#...###",
				"###############"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RaceCondition sut;
			sut.SetCheatMinTimeSaved(0);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(44ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RaceCondition sut;
			sut.SetCheatMinTimeSaved(50);
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(285ull, result);
		};
	};
	std::vector<std::string> Year2024_Day20::inputData1;
}
