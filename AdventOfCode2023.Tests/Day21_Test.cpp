#include "stdafx.h"
#include "Day21/Day21_StepCounter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day21;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day21)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"...........",
				".....###.#.",
				".###.##..#.",
				"..#.#...#..",
				"....#.#....",
				".##..S####.",
				".##..#...#.",
				".......##..",
				".##.#.####.",
				".##..##.##.",
				"..........."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			StepCounter sut;
			// Act:
			sut.SetStepCountPart1(6);
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(16ull, result);
		};
	};

	std::vector<std::string> Year2023_Day21::inputData1;
}
