#include "stdafx.h"
#include "Day09/Day09_MarbleMania.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day09;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day09)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "9 players; last marble is worth 25 points" });

			// Assert:
			Assert::AreEqual(32ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "10 players; last marble is worth 1618 points" });

			// Assert:
			Assert::AreEqual(8317ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "13 players; last marble is worth 7999 points" });

			// Assert:
			Assert::AreEqual(146373ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "17 players; last marble is worth 1104 points" });

			// Assert:
			Assert::AreEqual(2764ull, result);
		}

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "21 players; last marble is worth 6111 points" });

			// Assert:
			Assert::AreEqual(54718ull, result);
		}

		TEST_METHOD(CheckExample6_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "30 players; last marble is worth 5807 points" });

			// Assert:
			Assert::AreEqual(37305ull, result);
		}
	};
}