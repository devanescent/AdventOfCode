#include "stdafx.h"
#include "Day16/Day16_ReindeerMaze.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day16;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day16)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"###############",
				"#.......#....E#",
				"#.#.###.#.###.#",
				"#.....#.#...#.#",
				"#.###.#####.#.#",
				"#.#.#.......#.#",
				"#.#.#####.###.#",
				"#...........#.#",
				"###.#.#####.#.#",
				"#...#.....#.#.#",
				"#.#.#.###.#.#.#",
				"#.....#...#.#.#",
				"#.###.#.#.#.#.#",
				"#S..#.....#...#",
				"###############"
			};

			inputData2 = std::vector<std::string>
			{
				"#################",
				"#...#...#...#..E#",
				"#.#.#.#.#.#.#.#.#",
				"#.#.#.#...#...#.#",
				"#.#.#.#.###.#.#.#",
				"#...#.#.#.....#.#",
				"#.#.#.#.#.#####.#",
				"#.#...#.#.#.....#",
				"#.#.#####.#.###.#",
				"#.#.#.......#...#",
				"#.#.###.#####.###",
				"#.#.#...#.....#.#",
				"#.#.#.#####.###.#",
				"#.#.#.........#.#",
				"#.#.#.#########.#",
				"#S#.............#",
				"#################"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ReindeerMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(7036ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ReindeerMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(11048ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ReindeerMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(45ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			ReindeerMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(64ull, result);
		};
	};
	std::vector<std::string> Year2024_Day16::inputData1;
	std::vector<std::string> Year2024_Day16::inputData2;
}
