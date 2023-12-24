#include "stdafx.h"
#include "Day23\Day23_ALongWalk.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day23;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day23)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"#.#####################",
				"#.......#########...###",
				"#######.#########.#.###",
				"###.....#.>.>.###.#.###",
				"###v#####.#v#.###.#.###",
				"###.>...#.#.#.....#...#",
				"###v###.#.#.#########.#",
				"###...#.#.#.......#...#",
				"#####.#.#.#######.#.###",
				"#.....#.#.#.......#...#",
				"#.#####.#.#.#########v#",
				"#.#...#...#...###...>.#",
				"#.#.#v#######v###.###v#",
				"#...#.>.#...>.>.#.###.#",
				"#####v#.#.###v#.#.###.#",
				"#.....#...#...#.#.#...#",
				"#.#########.###.#.#.###",
				"#...###...#...#...#.###",
				"###.###.#.###v#####v###",
				"#...#...#.#.>.>.#.>.###",
				"#.###.###.#.###.#.#v###",
				"#.....###...###...#...#",
				"#####################.#"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ALongWalk sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(94ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ALongWalk sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(154ull, result);
		};
	};
	std::vector<std::string> Year2023_Day23::inputData1 = std::vector<std::string>();
}
