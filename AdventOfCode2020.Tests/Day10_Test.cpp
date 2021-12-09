#include "stdafx.h"
#include "Day10\Day10_AdapterArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day10;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day10)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"28",
				"33",
				"18",
				"42",
				"31",
				"14",
				"46",
				"20",
				"48",
				"47",
				"24",
				"23",
				"49",
				"45",
				"19",
				"38",
				"39",
				"11",
				"1",
				"32",
				"25",
				"35",
				"8",
				"17",
				"7",
				"9",
				"4",
				"2",
				"34",
				"10",
				"3"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			AdapterArray day10;

			// Act:
			uint64_t result = day10.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(220ull, result);
		}
	};

	std::vector<std::string> Day10::inputData = std::vector<std::string>();
}