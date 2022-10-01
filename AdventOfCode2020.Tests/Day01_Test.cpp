#include "stdafx.h"
#include "Day01\Day01_ReportRepair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day01;

namespace AdventOfCode::Year2020::Tests
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
				"1721",
				"979",
				"366",
				"299",
				"675",
				"1456"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			IntProcessor<IntProcessingMode::ValuePerLine> intProc;

			// Act:
			std::vector<int> result = intProc.Process(inputData);

			// Assert:
			Assert::AreEqual(1721, result[0]);
			Assert::AreEqual(979, result[1]);
			Assert::AreEqual(366, result[2]);
			Assert::AreEqual(299, result[3]);
			Assert::AreEqual(675, result[4]);
			Assert::AreEqual(1456, result[5]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ReportRepair sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(514579ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ReportRepair sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(241861950ull, result);
		}
	};

	std::vector<std::string> Day01::inputData = std::vector<std::string>();
}