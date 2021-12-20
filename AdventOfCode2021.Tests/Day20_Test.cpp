#include "stdafx.h"
#include "Day20\Day20_TrenchMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day20;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day20)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{ 
				"..#.#..#####.#.#.#.###.##.....###.##.#..###.####..#####..#....#..#..##..###..######.###...####..#..#####..##..#.#####...##.#.#..#.##..#.#......#.###.######.###.####...#.##.##..#..#..#####.....#.#....###..#.##......#.....#..#..#..##..#...##.######.####.####.#.#...#.......#..#.#.#...####.##.#......#..#...##.#.##..#...##.#.##..###.#......#.#.......#.#.#.####.###.##...#.....####.#..#..#.##.#....##..#.####....##...##..#...#......#.#.......#.......##..####..#...#.#.#...##..#.#..###..#####........#..####......#..#",
				"",
				"#..#.",
				"#....",
				"##..#",
				"..#..",
				"..###"
			};	
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TrenchMap day20;

			// Act:
			uint64_t result = day20.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(35ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			TrenchMap day20;

			// Act:
			uint64_t result = day20.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(3351ull, result);
		}
	};

	std::vector<std::string> Day20::inputData = std::vector<std::string>();
}