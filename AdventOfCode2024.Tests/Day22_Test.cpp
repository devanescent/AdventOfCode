#include "stdafx.h"
#include "Day22/Day22_MonkeyMarket.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day22;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day22)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1",
				"10",
				"100",
				"2024"
			};

			inputData2 = std::vector<std::string>
			{
				"1",
				"2",
				"3",
				"2024"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MonkeyMarket sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(37327623ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			MonkeyMarket sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(23ull, result);
		};
	};
	std::vector<std::string> Year2024_Day22::inputData1;
	std::vector<std::string> Year2024_Day22::inputData2;
}
