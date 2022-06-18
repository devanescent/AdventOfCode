#include "stdafx.h"
#include "Day11\Day11_ChronalCharge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day11;

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

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ChronalCharge sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);

			// Assert:
			Assert::AreEqual(0ull, result);
		}
	};

	std::vector<std::string> Year2018_Day11::inputData = std::vector<std::string>();
	std::vector<std::string> Year2018_Day11::inputData2 = std::vector<std::string>();
}