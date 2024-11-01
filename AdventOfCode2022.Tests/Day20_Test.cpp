#include "stdafx.h"
#include "Day20/Day20_GrovePositioningSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day20;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day20)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1",
				"2",
				"-3",
				"3",
				"-2",
				"0",
				"4"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			GrovePositioningSystem sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			GrovePositioningSystem sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(1623178306ull, result);
		};
	};

	std::vector<std::string> Year2022_Day20::inputData1;
}
