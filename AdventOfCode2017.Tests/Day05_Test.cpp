#include "stdafx.h"
#include "Day05/Day05_AMazeOfTwistyTrampolinesAllAlike.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day05;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day05)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0",
				"3",
				"0",
				"1",
				"-3"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			AMazeOfTwistyTrampolinesAllAlike sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(5ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			AMazeOfTwistyTrampolinesAllAlike sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(10ull, result);
		};
	};
	std::vector<std::string> Year2017_Day05::inputData1;
}
