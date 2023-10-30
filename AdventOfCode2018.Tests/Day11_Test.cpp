#include "stdafx.h"
#include "Day11\Day11_ChronalCharge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day11;
using namespace std::string_literals;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day11)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string> { "18" };
			inputData2 = std::vector<std::string> { "42" };
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual("33,45"s, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual("21,61"s, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual("90,269,16"s, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			std::string result = sut.GetResultOnPart2(inputData2);

			// Assert:
			Assert::AreEqual("232,251,12"s, result);
		}
	};

	std::vector<std::string> Year2018_Day11::inputData = std::vector<std::string>();
	std::vector<std::string> Year2018_Day11::inputData2 = std::vector<std::string>();
}