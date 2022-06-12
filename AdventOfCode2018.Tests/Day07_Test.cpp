#include "stdafx.h"
#include "Day07\Day07_TheSumOfItsParts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day07;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day07)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"Step C must be finished before step A can begin.",
				"Step C must be finished before step F can begin.",
				"Step A must be finished before step B can begin.",
				"Step A must be finished before step D can begin.",
				"Step B must be finished before step E can begin.",
				"Step D must be finished before step E can begin.",
				"Step F must be finished before step E can begin."
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TheSumOfItsParts sut(0, 0);

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			TheSumOfItsParts sut(2, 0);

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(15ull, result);
		}
	};

	std::vector<std::string> Year2018_Day07::inputData = std::vector<std::string>();
}