#include "stdafx.h"
#include "Day17/Day17_Spinlock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day17;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day17)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Spinlock sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "3" });
			// Assert:
			Assert::AreEqual(638ull, result);
		};
	};
}
