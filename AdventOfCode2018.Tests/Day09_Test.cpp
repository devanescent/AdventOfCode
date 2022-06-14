#include "stdafx.h"
#include "Day09\Day09_MarbleMania.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day09;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day09)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;
		static std::vector<std::string> inputData6;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>{ "9 players; last marble is worth 25 points" };
			inputData2 = std::vector<std::string>{ "10 players; last marble is worth 1618 points" };
			inputData3 = std::vector<std::string>{ "13 players; last marble is worth 7999 points" };
			inputData4 = std::vector<std::string>{ "17 players; last marble is worth 1104 points" };
			inputData5 = std::vector<std::string>{ "21 players; last marble is worth 6111 points" };
			inputData6 = std::vector<std::string> { "30 players; last marble is worth 5807 points" };
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(32ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(8317ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(146373ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);

			// Assert:
			Assert::AreEqual(2764ull, result);
		}

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData5);

			// Assert:
			Assert::AreEqual(54718ull, result);
		}

		TEST_METHOD(CheckExample6_Part1)
		{
			// Arrange:
			MarbleMania sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData6);

			// Assert:
			Assert::AreEqual(37305ull, result);
		}
	};

	std::vector<std::string> Year2018_Day09::inputData = std::vector<std::string>();
	std::vector<std::string> Year2018_Day09::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day09::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day09::inputData4 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day09::inputData5 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day09::inputData6 = std::vector<std::string>();
}