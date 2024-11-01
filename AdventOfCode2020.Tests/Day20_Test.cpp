#include "stdafx.h"
#include "Day20/Day20_JurassicJigsaw.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day20;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Tile>(const Tile& t) { return to_wstring(t.ToString()); }

namespace AdventOfCode::Year2020::Tests
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
				"Tile 2311:",
				"..##.#..#.",
				"##..#.....",
				"#...##..#.",
				"####.#...#",
				"##.##.###.",
				"##...#.###",
				".#.#.#..##",
				"..#....#..",
				"###...#.#.",
				"..###..###",
				"",
				"Tile 1951:",
				"#.##...##.",
				"#.####...#",
				".....#..##",
				"#...######",
				".##.#....#",
				".###.#####",
				"###.##.##.",
				".###....#.",
				"..#.#..#.#",
				"#...##.#..",
				"",
				"Tile 1171:",
				"####...##.",
				"#..##.#..#",
				"##.#..#.#.",
				".###.####.",
				"..###.####",
				".##....##.",
				".#...####.",
				"#.##.####.",
				"####..#...",
				".....##...",
				"",
				"Tile 1427:",
				"###.##.#..",
				".#..#.##..",
				".#.##.#..#",
				"#.#.#.##.#",
				"....#...##",
				"...##..##.",
				"...#.#####",
				".#.####.#.",
				"..#..###.#",
				"..##.#..#.",
				"",
				"Tile 1489:",
				"##.#.#....",
				"..##...#..",
				".##..##...",
				"..#...#...",
				"#####...#.",
				"#..#.#.#.#",
				"...#.#.#..",
				"##.#...##.",
				"..##.##.##",
				"###.##.#..",
				"",
				"Tile 2473:",
				"#....####.",
				"#..#.##...",
				"#.##..#...",
				"######.#.#",
				".#...#.#.#",
				".#########",
				".###.#..#.",
				"########.#",
				"##...##.#.",
				"..###.#.#.",
				"",
				"Tile 2971:",
				"..#.#....#",
				"#...###...",
				"#.#.###...",
				"##.##..#..",
				".#####..##",
				".#..####.#",
				"#..#.#..#.",
				"..####.###",
				"..#.#.###.",
				"...#.#.#.#",
				"",
				"Tile 2729:",
				"...#.#.#.#",
				"####.#....",
				"..#.#.....",
				"....#..#.#",
				".##..##.#.",
				".#.####...",
				"####.#.#..",
				"##.####...",
				"##..#.##..",
				"#.##...##.",
				"",
				"Tile 3079:",
				"#.#.#####.",
				".#..######",
				"..#.......",
				"######....",
				"####.#..#.",
				".#...#.##.",
				"#.#####.##",
				"..#.###...",
				"..#.......",
				"..#.###..."
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			TileProcessor tileProc;

			// Act:
			std::vector<Tile> result = tileProc.Process(inputData);

			// Assert:
			Assert::AreEqual(Tile(2311, "..##.#..#.", "...#.##..#", "###..###..", ".#..#####."), result[0], L"Tile no. 1 incorrect");
			Assert::AreEqual(Tile(1489, "##.#.#....", ".....#..#.", "..#.##.###", "#.#.##...#"), result[4], L"Tile no. 5 incorrect");
			Assert::AreEqual(Tile(3079, "#.#.#####.", ".#....#...", "...###.#..", "...#.##..#"), result[8], L"Tile no. 9 incorrect");
		}

		TEST_METHOD(MatchTiles)
		{
			Tile t1(1, "abc", "def", "ghi", "jkl");
			Tile t2(2, "xyz", "123", "abc", "nmo");
			Tile t3(3, "opq", "rst", "uvw", "zyx");

			Assert::IsTrue(t1.Match(t2));
			Assert::IsTrue(t2.Match(t3));
			Assert::IsFalse(t1.Match(t3));
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			JurassicJigsaw day20;

			// Act:
			uint64_t result = day20.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(20899048083289ull, result);
		}
	};

	std::vector<std::string> Day20::inputData;
}