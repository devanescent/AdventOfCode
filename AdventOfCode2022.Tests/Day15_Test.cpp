#include "stdafx.h"
#include "Day15/Day15_BeaconExclusionZone.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day15;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day15)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Sensor at x=2, y=18: closest beacon is at x=-2, y=15",
				"Sensor at x=9, y=16: closest beacon is at x=10, y=16",
				"Sensor at x=13, y=2: closest beacon is at x=15, y=3",
				"Sensor at x=12, y=14: closest beacon is at x=10, y=16",
				"Sensor at x=10, y=20: closest beacon is at x=10, y=16",
				"Sensor at x=14, y=17: closest beacon is at x=10, y=16",
				"Sensor at x=8, y=7: closest beacon is at x=2, y=10",
				"Sensor at x=2, y=0: closest beacon is at x=2, y=10",
				"Sensor at x=0, y=11: closest beacon is at x=2, y=10",
				"Sensor at x=20, y=14: closest beacon is at x=25, y=17",
				"Sensor at x=17, y=20: closest beacon is at x=21, y=22",
				"Sensor at x=16, y=7: closest beacon is at x=15, y=3",
				"Sensor at x=14, y=3: closest beacon is at x=15, y=3",
				"Sensor at x=20, y=1: closest beacon is at x=15, y=3"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			BeaconExclusionZone sut(10);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(26ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			BeaconExclusionZone sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(56000011ull, result);
		};
	};

	std::vector<std::string> Year2022_Day15::inputData1;
}
