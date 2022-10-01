#include "stdafx.h"
#include "Day03\Day03_TobogganTrajectory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day03;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day03)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"..##.......",
				"#...#...#..",
				".#....#..#.",
				"..#.#...#.#",
				".#...##..#.",
				"..#.##.....",
				".#.#.#....#",
				".#........#",
				"#.##...#...",
				"#...##....#",
				".#..#...#.#"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TobogganTrajectory sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(7ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			TobogganTrajectory sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(336ull, result);
		}
	};

	std::vector<std::string> Day03::inputData = std::vector<std::string>();
}