#include "stdafx.h"
#include "Day11/Day11_HexEd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day11;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day11)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "ne,ne,ne" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "ne,ne,sw,sw" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "ne,ne,s,s" });
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "se,sw,se,sw,sw" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};
	};
}
