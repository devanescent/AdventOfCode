#include "stdafx.h"
#include "Day06\Day06_ChronalCoordinates.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day06;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day06)
	{
	public:
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ChronalCoordinates sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(
				{
					"1, 1",
					"1, 6",
					"8, 3",
					"3, 4",
					"5, 5",
					"8, 9"
				}
			);

			// Assert:
			Assert::AreEqual(17ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ChronalCoordinates sut(32);

			// Act:
			uint64_t result = sut.GetResultOnPart2(
				{
					"1, 1",
					"1, 6",
					"8, 3",
					"3, 4",
					"5, 5",
					"8, 9"
				}
			);

			// Assert:
			Assert::AreEqual(16ull, result);
		}
	};
}