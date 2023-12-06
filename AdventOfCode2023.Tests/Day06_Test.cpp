#include "stdafx.h"
#include "Day06\Day06_WaitForIt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day06;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day06)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Time:      7  15   30",
				"Distance:  9  40  200"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			WaitForIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(288ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			WaitForIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(71503ull, result);
		};
	};
	std::vector<std::string> Year2023_Day06::inputData1 = std::vector<std::string>();
}
