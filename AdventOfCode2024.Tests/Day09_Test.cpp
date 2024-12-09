#include "stdafx.h"
#include "Day09/Day09_DiskFragmenter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day09;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day09)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			DiskFragmenter sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "2333133121414131402" });
			// Assert:
			Assert::AreEqual(1928ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			DiskFragmenter sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2({ "2333133121414131402" });
			// Assert:
			Assert::AreEqual(2858ull, result);
		};
	};
}
