#include "stdafx.h"
#include "Day15/Day15_DuelingGenerators.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day15;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day15)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Generator A starts with 65",
				"Generator B starts with 8921"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			DuelingGenerators sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(588ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			DuelingGenerators sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(309ull, result);
		};
	};

	std::vector<std::string> Year2017_Day15::inputData1;
}
