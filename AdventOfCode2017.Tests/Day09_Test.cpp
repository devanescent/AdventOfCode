#include "stdafx.h"
#include "Day09/Day09_StreamProcessing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day09;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day09)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{}" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{{}}}" });
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{},{}}" });
			// Assert:
			Assert::AreEqual(5ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{{},{},{{}}}}" });
			// Assert:
			Assert::AreEqual(16ull, result);
		};

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{<a>,<a>,<a>,<a>}" });
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample6_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{<ab>},{<ab>},{<ab>},{<ab>}}" });
			// Assert:
			Assert::AreEqual(9ull, result);
		};

		TEST_METHOD(CheckExample7_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{<!!>},{<!!>},{<!!>},{<!!>}}" });
			// Assert:
			Assert::AreEqual(9ull, result);
		};

		TEST_METHOD(CheckExample8_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(std::vector<std::string> { "{{<a!>},{<a!>},{<a!>},{<ab>}}" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<>" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<random characters>" });
			// Assert:
			Assert::AreEqual(17ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<<<<>" });
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<{!>}>" });
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<!!>" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample6_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<!!!>>" });
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample7_Part2)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(std::vector<std::string> { "<{o\"i!a,<{i<a>" });
			// Assert:
			Assert::AreEqual(10ull, result);
		};
	};
}
