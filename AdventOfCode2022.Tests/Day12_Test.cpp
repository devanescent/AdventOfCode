#include "stdafx.h"
#include "Day12/Day12_HillClimbingAlgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day12;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day12)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Sabqponm",
				"abcryxxl",
				"accszExk",
				"acctuvwj",
				"abdefghi"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HillClimbingAlgorithm sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(31ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HillClimbingAlgorithm sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(29ull, result);
		};
	};

	std::vector<std::string> Year2022_Day12::inputData1;
}
