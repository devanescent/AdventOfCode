#include "stdafx.h"
#include "Day09/Day09_EncodingError.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day09;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day09)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"35",
				"20",
				"15",
				"25",
				"47",
				"40",
				"62",
				"55",
				"65",
				"95",
				"102",
				"117",
				"150",
				"182",
				"127",
				"219",
				"299",
				"277",
				"309",
				"576"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			EncodingError sut(5);

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(127ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			EncodingError sut(5);

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(62ull, result);
		}
	};

	std::vector<std::string> Day09::inputData;
}