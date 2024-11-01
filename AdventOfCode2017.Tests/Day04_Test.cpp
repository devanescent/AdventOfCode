#include "stdafx.h"
#include "Day04/Day04_HighEntropyPassphrases.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day04;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day04)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "aa bb cc dd ee" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "aa bb cc dd aa" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "aa bb cc dd aaa" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "abcde fghij" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "abcde xyz ecdab" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "a ab abc abd abf abj" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "iiii oiii ooii oooi oooo" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "oiii ioii iioi iiio" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};
	};
}
