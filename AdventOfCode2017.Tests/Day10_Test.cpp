#include "stdafx.h"
#include "Day10\Day10_KnotHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day10;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day10)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			KnotHash sut;
			sut.SetNumberListLength(5);
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "3, 4, 1, 5" });
			// Assert:
			Assert::AreEqual(12ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "AoC 2017" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "1,2,3" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "1,2,4" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};
	};
}
