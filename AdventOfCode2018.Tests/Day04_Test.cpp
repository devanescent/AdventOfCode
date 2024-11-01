#include "stdafx.h"
#include "Day04/Day04_ReposeRecord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day04;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<GuardDutyRecord>(const GuardDutyRecord& gdr) { return to_wstring(gdr.ToString()); }

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day04)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"[1518-11-01 00:00] Guard #10 begins shift",
				"[1518-11-01 00:05] falls asleep",
				"[1518-11-01 00:25] wakes up",
				"[1518-11-01 00:30] falls asleep",
				"[1518-11-01 00:55] wakes up",
				"[1518-11-01 23:58] Guard #99 begins shift",
				"[1518-11-02 00:40] falls asleep",
				"[1518-11-02 00:50] wakes up",
				"[1518-11-03 00:05] Guard #10 begins shift",
				"[1518-11-03 00:24] falls asleep",
				"[1518-11-03 00:29] wakes up",
				"[1518-11-04 00:02] Guard #99 begins shift",
				"[1518-11-04 00:36] falls asleep",
				"[1518-11-04 00:46] wakes up",
				"[1518-11-05 00:03] Guard #99 begins shift",
				"[1518-11-05 00:45] falls asleep",
				"[1518-11-05 00:55] wakes up",
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			GuardDutyRecordProcessor sut;

			// Act:
			std::vector<GuardDutyRecordProcessor::result_type> result = sut.Process(inputData);

			// Assert:
			std::unique_ptr<GuardDutyRecord> res0 = std::make_unique<BeginShiftRecord>(1518, 11, 1, 0, 0, 10);
			Assert::AreEqual(*res0, *result[0]);

			std::unique_ptr<GuardDutyRecord> res1 = std::make_unique<SleepRecord>(1518, 11, 1, 0, 5, true);
			Assert::AreEqual(*res1, *result[1]);

			std::unique_ptr<GuardDutyRecord> res2 = std::make_unique<SleepRecord>(1518, 11, 1, 0, 25, false);
			Assert::AreEqual(*res2, *result[2]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ReposeRecord day04;

			// Act:
			uint64_t result = day04.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(240ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ReposeRecord day04;

			// Act:
			uint64_t result = day04.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(4455ull, result);
		}
	};

	std::vector<std::string> Year2018_Day04::inputData;
}