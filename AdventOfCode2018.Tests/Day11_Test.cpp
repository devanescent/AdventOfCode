#include "stdafx.h"
#include "Day11/Day11_ChronalCharge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day11;
using namespace std::string_literals;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day11)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart1({ "18" });

			// Assert:
			Assert::AreEqual("33,45"s, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart1({ "42" });

			// Assert:
			Assert::AreEqual("21,61"s, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart2({ "18" });

			// Assert:
			Assert::AreEqual("90,269,16"s, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart2({ "42" });

			// Assert:
			Assert::AreEqual("232,251,12"s, result);
		}
	};
}