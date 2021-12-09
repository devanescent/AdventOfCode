#include "stdafx.h"
#include "Day15\Day15_RambunctiousRecitation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day15;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day15)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"0,3,6"
			};

			inputData2 = std::vector<std::string>
			{
				"3,2,1"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			IntProcessor<IntProcessingMode::ValuesAsSingleLine> intProc;

			// Act:
			std::vector<int> result = intProc.Process(inputData);

			// Assert:
			Assert::AreEqual(0, result[0]);
			Assert::AreEqual(3, result[1]);
			Assert::AreEqual(6, result[2]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			RambunctiousRecitation day15(10);

			// Act:
			uint64_t result = day15.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			RambunctiousRecitation day15(2020);

			// Act:
			uint64_t result = day15.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(438ull, result);
		}
	};

	std::vector<std::string> Day15::inputData = std::vector<std::string>();
	std::vector<std::string> Day15::inputData2 = std::vector<std::string>();
}