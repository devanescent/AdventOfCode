#include "stdafx.h"
#include "Day13/Day13_PointOfIncidence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day13;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day13)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"#.##..##.",
				"..#.##.#.",
				"##......#",
				"##......#",
				"..#.##.#.",
				"..##..##.",
				"#.#.##.#.",
				"",
				"#...##..#",
				"#....#..#",
				"..##..###",
				"#####.##.",
				"#####.##.",
				"..##..###",
				"#....#..#"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PointOfIncidence sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(405ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PointOfIncidence sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(400ull, result);
		};
	};

	std::vector<std::string> Year2023_Day13::inputData1;
}
