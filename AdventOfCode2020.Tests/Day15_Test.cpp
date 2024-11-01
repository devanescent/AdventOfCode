#include "stdafx.h"
#include "Day15/Day15_RambunctiousRecitation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day15;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day15)
	{
	public:
		TEST_METHOD(ParseInput)
		{
			// Arrange:
			IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine> intProc;

			// Act:
			std::vector<int> result = intProc.Process({ "0,3,6" });

			// Assert:
			Assert::AreEqual(0, result[0]);
			Assert::AreEqual(3, result[1]);
			Assert::AreEqual(6, result[2]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			RambunctiousRecitation day15(10);

			// Act:
			uint64_t result = day15.GetResultOnPart1({ "0,3,6" });

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			RambunctiousRecitation day15(2020);

			// Act:
			uint64_t result = day15.GetResultOnPart1({ "0,3,6" });

			// Assert:
			Assert::AreEqual(436ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			RambunctiousRecitation day15(30000000);

			// Act:
			uint64_t result = day15.GetResultOnPart2({ "0,3,6" });

			// Assert:
			Assert::AreEqual(175594ull, result);
		}
	};
}