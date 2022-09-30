#include "stdafx.h"
#include "Day15\Day15_BeverageBandits.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day15;

namespace AdventOfCode::Year2018::Tests
{
	// In addition to the examples from the problem, also used the testcases from
	// https://github.com/ShaneMcC/aoc-2018/tree/master/15/tests
	TEST_CLASS(Year2018_Day15)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#######",
				"#.G...#",
				"#...EG#",
				"#.#.#G#",
				"#..G#E#",
				"#.....#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(27730ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#######",
				"#G..#E#",
				"#E#E.E#",
				"#G.##.#",
				"#...#E#",
				"#...E.#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(36334ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#######",
				"#E..EG#",
				"#.#G.E#",
				"#E.##E#",
				"#G..#.#",
				"#..E#.#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(39514ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#######",
				"#E.G#.#",
				"#.#G..#",
				"#G.#.G#",
				"#G..#.#",
				"#...E.#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(27755ull, result);
		}

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#######",
				"#.E...#",
				"#.#..G#",
				"#.###.#",
				"#E#G#G#",
				"#...#G#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(28944ull, result);
		}

		TEST_METHOD(CheckExample6_Part1)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({
				"#########",
				"#G......#",
				"#.E.#...#",
				"#..##..G#",
				"#...##..#",
				"#...#...#",
				"#.G...G.#",
				"#.....G.#",
				"#########"
			});
			// Assert:
			Assert::AreEqual(18740ull, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({
				"#######",
				"#.G...#",
				"#...EG#",
				"#.#.#G#",
				"#..G#E#",
				"#.....#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(4988ull, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({
				"#######",
				"#E..EG#",
				"#.#G.E#",
				"#E.##E#",
				"#G..#.#",
				"#..E#.#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(31284ull, result);
		}

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({
				"#######",
				"#E.G#.#",
				"#.#G..#",
				"#G.#.G#",
				"#G..#.#",
				"#...E.#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(3478ull, result);
		}

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({
				"#######",
				"#.E...#",
				"#.#..G#",
				"#.###.#",
				"#E#G#G#",
				"#...#G#",
				"#######"
				});

			// Assert:
			Assert::AreEqual(6474ull, result);
		}

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			BeverageBandits sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({
				"#########",
				"#G......#",
				"#.E.#...#",
				"#..##..G#",
				"#...##..#",
				"#...#...#",
				"#.G...G.#",
				"#.....G.#",
				"#########"
				});
			// Assert:
			Assert::AreEqual(1140ull, result);
		}
	};
}