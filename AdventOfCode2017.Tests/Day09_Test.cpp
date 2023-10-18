#include "stdafx.h"
#include "Day09\Day09_StreamProcessing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day09;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day09)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;
		static std::vector<std::string> inputData6;
		static std::vector<std::string> inputData7;
		static std::vector<std::string> inputData8;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"{}"
			};

			inputData2 = std::vector<std::string>
			{
				"{{{}}}"
			};

			inputData3 = std::vector<std::string>
			{
				"{{},{}}"
			};

			inputData4 = std::vector<std::string>
			{
				"{{{},{},{{}}}}"
			};

			inputData5 = std::vector<std::string>
			{
				"{<a>,<a>,<a>,<a>}"
			};

			inputData6 = std::vector<std::string>
			{
				"{{<ab>},{<ab>},{<ab>},{<ab>}}"
			};

			inputData7 = std::vector<std::string>
			{
				"{{<!!>},{<!!>},{<!!>},{<!!>}}"
			};

			inputData8 = std::vector<std::string>
			{
				"{{<a!>},{<a!>},{<a!>},{<ab>}}"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(5ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);
			// Assert:
			Assert::AreEqual(16ull, result);
		};

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData5);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample6_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData6);
			// Assert:
			Assert::AreEqual(9ull, result);
		};

		TEST_METHOD(CheckExample7_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData7);
			// Assert:
			Assert::AreEqual(9ull, result);
		};

		TEST_METHOD(CheckExample8_Part1)
		{
			// Arrange:
			StreamProcessing sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData8);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

	};
	std::vector<std::string> Year2017_Day09::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData4 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData5 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData6 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData7 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day09::inputData8 = std::vector<std::string>();
}
