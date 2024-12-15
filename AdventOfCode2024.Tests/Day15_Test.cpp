#include "stdafx.h"
#include "Day15/Day15_WarehouseWoes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day15;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day15)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"########",
				"#..O.O.#",
				"##@.O..#",
				"#...O..#",
				"#.#.O..#",
				"#...O..#",
				"#......#",
				"########",
				"",
				"<^^>>>vv<v>>v<<"
			};

			inputData2 = std::vector<std::string>
			{
				"##########",
				"#..O..O.O#",
				"#......O.#",
				"#.OO..O.O#",
				"#..O@..O.#",
				"#O#..O...#",
				"#O..O..O.#",
				"#.OO.O.OO#",
				"#....O...#",
				"##########",
				"",
				"<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^",
				"vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v",
				"><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<",
				"<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^",
				"^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><",
				"^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^",
				">^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^",
				"<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>",
				"^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>",
				"v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^"
			};

			inputData3 = std::vector<std::string>
			{
				"#######",
				"#...#.#",
				"#.....#",
				"#..OO@#",
				"#..O..#",
				"#.....#",
				"#######",
				"",
				"<vv<<^^<<^^"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			WarehouseWoes sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(2028ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			WarehouseWoes sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(10092ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			WarehouseWoes sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(618ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			WarehouseWoes sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(9021ull, result);
		};
	};
	std::vector<std::string> Year2024_Day15::inputData1;
	std::vector<std::string> Year2024_Day15::inputData2;
	std::vector<std::string> Year2024_Day15::inputData3;
}
