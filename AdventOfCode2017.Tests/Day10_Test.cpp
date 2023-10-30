#include "stdafx.h"
#include "Day10\Day10_KnotHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day10;
using namespace std::string_literals;

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
			std::string result = sut.GetResultOnPart2(std::vector<std::string> { "" });
			// Assert:
			Assert::AreEqual("a2582a3a0e66e6e86e3812dcb672a272"s, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			std::string result = sut.GetResultOnPart2(std::vector<std::string> { "AoC 2017" });
			// Assert:
			Assert::AreEqual("33efeb34ea91902bb2f59c9920caa6cd"s, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			std::string result = sut.GetResultOnPart2(std::vector<std::string> { "1,2,3" });
			// Assert:
			Assert::AreEqual("3efbe78a8d82f29979031a4aa0b16a9d"s, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			KnotHash sut;
			// Act:
			std::string result = sut.GetResultOnPart2(std::vector<std::string> { "1,2,4" });
			// Assert:
			Assert::AreEqual("63960835bcdc130f0b66d7ff4f6a5a8e"s, result);
		};
	};
}
