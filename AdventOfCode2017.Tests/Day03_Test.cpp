#include "stdafx.h"
#include "Day03/Day03_SpiralMemory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day03;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day03)
	{
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "1" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "12" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "23" });
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "1024" });
			// Assert:
			Assert::AreEqual(31ull, result);
		};
	};
}
