#include "stdafx.h"
#include "Day01\Day01_ChronalCalibration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day01;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Day01)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"+1",
				"-2",
				"+3",
				"+1"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			IntProcessor<IntProcessingMode::ValuePerLine> intProc;

			// Act:
			std::vector<int> result = intProc.Process(inputData);

			// Assert:
			Assert::AreEqual(+1, result[0]);
			Assert::AreEqual(-2, result[1]);
			Assert::AreEqual(+3, result[2]);
			Assert::AreEqual(+1, result[3]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ChronalCalibration day01;

			// Act:
			uint64_t result = day01.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(3ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ChronalCalibration day01;

			// Act:
			uint64_t result = day01.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(2ull, result);
		}
	};

	std::vector<std::string> Day01::inputData = std::vector<std::string>();
}