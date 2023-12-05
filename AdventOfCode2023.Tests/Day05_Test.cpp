#include "stdafx.h"
#include "Day05\Day05_IfYouGiveASeedAFertilizer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day05;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day05)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"seeds: 79 14 55 13",
				"",
				"seed-to-soil map:",
				"50 98 2",
				"52 50 48",
				"",
				"soil-to-fertilizer map:",
				"0 15 37",
				"37 52 2",
				"39 0 15",
				"",
				"fertilizer-to-water map:",
				"49 53 8",
				"0 11 42",
				"42 0 7",
				"57 7 4",
				"",
				"water-to-light map:",
				"88 18 7",
				"18 25 70",
				"",
				"light-to-temperature map:",
				"45 77 23",
				"81 45 19",
				"68 64 13",
				"",
				"temperature-to-humidity map:",
				"0 69 1",
				"1 0 69",
				"",
				"humidity-to-location map:",
				"60 56 37",
				"56 93 4"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			IfYouGiveASeedAFertilizer sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(35ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			IfYouGiveASeedAFertilizer sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(46ull, result);
		};
	};
	std::vector<std::string> Year2023_Day05::inputData1 = std::vector<std::string>();
}
