#include "stdafx.h"
#include "Day06/Day06_GuardGallivant.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day06;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day06)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"....#.....",
				".........#",
				"..........",
				"..#.......",
				".......#..",
				"..........",
				".#..^.....",
				"........#.",
				"#.........",
				"......#..."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			GuardGallivant sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(41ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			GuardGallivant sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(6ull, result);
		};
	};
	std::vector<std::string> Year2024_Day06::inputData1;
}
