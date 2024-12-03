#include "stdafx.h"
#include "Day03/Day03_MullItOver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day03;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day03)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MullItOver sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))" });
			// Assert:
			Assert::AreEqual(161ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			MullItOver sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2({ "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))" });
			// Assert:
			Assert::AreEqual(48ull, result);
		};
	};
}
