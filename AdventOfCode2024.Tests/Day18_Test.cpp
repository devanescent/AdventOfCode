#include "stdafx.h"
#include "Day18/Day18_RAMRun.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day18;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day18)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"5,4",
				"4,2",
				"4,5",
				"3,0",
				"2,1",
				"6,3",
				"2,4",
				"1,5",
				"0,6",
				"3,3",
				"2,6",
				"5,1",
				"1,2",
				"5,5",
				"2,5",
				"6,5",
				"1,4",
				"0,4",
				"6,4",
				"1,1",
				"6,1",
				"1,0",
				"0,5",
				"1,6",
				"2,0"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RAMRun sut;
			sut.SetMemorySize(6);
			sut.SetSimulationCount(12);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(22ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RAMRun sut;
			sut.SetMemorySize(6);
			sut.SetSimulationCount(12);
			// Act:
			std::string result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(std::string("6,1"), result);
		};
	};
	std::vector<std::string> Year2024_Day18::inputData1;
}
