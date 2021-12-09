#include "stdafx.h"
#include "Day05\Day05_BinaryBoarding.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day05;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day05)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"FBFBBFFRLR",
				"BFFFBBFRRR",
				"FFFBBBFRRR",
				"BBFFBBFRLL"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			BinaryBoarding day05 = BinaryBoarding(128, 8);

			// Act:
			uint64_t result = day05.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(820ull, result);
		}
	};

	std::vector<std::string> Day05::inputData = std::vector<std::string>();
}