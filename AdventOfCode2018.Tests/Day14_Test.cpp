#include "stdafx.h"
#include "Day14\Day14_ChocolateCharts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day14;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day14)
	{
	public:
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "5" });

			// Assert:
			Assert::AreEqual(124515891ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "18" });

			// Assert:
			Assert::AreEqual(9251071085ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "2018" });

			// Assert:
			Assert::AreEqual(5941429882ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({ "51589" });

			// Assert:
			Assert::AreEqual(9ull, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({ "01245" });

			// Assert:
			Assert::AreEqual(5ull, result);
		}

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({ "92510" });

			// Assert:
			Assert::AreEqual(18ull, result);
		}

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			ChocolateCharts sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2({ "59414" });

			// Assert:
			Assert::AreEqual(2018ull, result);
		}
	};
}