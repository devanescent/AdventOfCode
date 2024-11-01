#include "stdafx.h"
#include "Day17/Day17_PyroclasticFlow.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day17;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day17)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PyroclasticFlow sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3068ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PyroclasticFlow sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(1514285714288ull, result);
		};
	};

	std::vector<std::string> Year2022_Day17::inputData1;
}
