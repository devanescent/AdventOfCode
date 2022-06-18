#include "stdafx.h"
#include "Day08\Day08_MemoryManeuver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day08;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day08)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>{ "2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2" };
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			MemoryManeuver sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(138ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			MemoryManeuver sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(66ull, result);
		}
	};

	std::vector<std::string> Year2018_Day08::inputData = std::vector<std::string>();
}