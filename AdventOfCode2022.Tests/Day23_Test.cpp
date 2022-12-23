#include "stdafx.h"
#include "Day23\Day23_UnstableDiffusion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day23;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day23)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				".....",
				"..##.",
				"..#..",
				".....",
				"..##.",
				"....."
			};

			inputData2 = std::vector<std::string>
			{
				"....#..",
				"..###.#",
				"#...#.#",
				".#...##",
				"#.###..",
				"##.#.##",
				".#..#.."
			};
		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			UnstableDiffusion sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(110ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			UnstableDiffusion sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(20ull, result);
		};

	};
	std::vector<std::string> Year2022_Day23::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day23::inputData2 = std::vector<std::string>();
}
