#include "stdafx.h"
#include "Day04/Day04_CampCleanup.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day04;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day04)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"2-4,6-8",
				"2-3,4-5",
				"5-7,7-9",
				"2-8,3-7",
				"6-6,4-6",
				"2-6,4-8"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CampCleanup sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			CampCleanup sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);
			// Assert:
			Assert::AreEqual(4ull, result);
		};
	};

	std::vector<std::string> Year2022_Day04::inputData;
}
