#include "stdafx.h"
#include "Day09\Day09_MirageMaintenance.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day09;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day09)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0 3 6 9 12 15",
				"1 3 6 10 15 21",
				"10 13 16 21 30 45"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MirageMaintenance sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(114ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			MirageMaintenance sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(2ull, result);
		};
	};
	std::vector<std::string> Year2023_Day09::inputData1 = std::vector<std::string>();
}
