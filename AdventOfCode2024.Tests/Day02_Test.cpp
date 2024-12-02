#include "stdafx.h"
#include "Day02/Day02_RedNosedReports.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day02;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day02)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"7 6 4 2 1",
				"1 2 7 8 9",
				"9 7 6 2 1",
				"1 3 2 4 5",
				"8 6 4 4 1",
				"1 3 6 7 9"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RedNosedReports sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RedNosedReports sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(4ull, result);
		};
	};
	std::vector<std::string> Year2024_Day02::inputData1;
}
