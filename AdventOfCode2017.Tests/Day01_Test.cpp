#include "stdafx.h"
#include "Day01/Day01_InverseCaptcha.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day01;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day01)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "1122" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "1111" });
			// Assert:
			Assert::AreEqual(4ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "1234" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1({ "91212129" });
			// Assert:
			Assert::AreEqual(9ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2({ "91212129" });
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "1221" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "123425" });
			// Assert:
			Assert::AreEqual(4ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "123123" });
			// Assert:
			Assert::AreEqual(12ull, result);
		};

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "12131415" });
			// Assert:
			Assert::AreEqual(4ull, result);
		};

	};
}
