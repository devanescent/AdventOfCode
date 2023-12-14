#include "stdafx.h"
#include "Day14\Day14_ParabolicReflectorDish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day14;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day14)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"O....#....",
				"O.OO#....#",
				".....##...",
				"OO.#O....O",
				".O.....O#.",
				"O.#..O.#.#",
				"..O..#O..O",
				".......O..",
				"#....###..",
				"#OO..#...."
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ParabolicReflectorDish sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(136ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ParabolicReflectorDish sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(64ull, result);
		};
	};
	std::vector<std::string> Year2023_Day14::inputData1 = std::vector<std::string>();
}
