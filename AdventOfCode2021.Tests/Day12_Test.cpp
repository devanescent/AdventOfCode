#include "stdafx.h"
#include "Day12\Day12_PassagePathing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day12;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day12)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"start-A",
				"start-b",
				"A-c",
				"A-b",
				"b-d",
				"A-end",
				"b-end"
			};

			inputData2 = std::vector<std::string>
			{
				"dc-end",
				"HN-start",
				"start-kj",
				"dc-start",
				"dc-HN",
				"LN-dc",
				"HN-end",
				"kj-sa",
				"kj-HN",
				"kj-dc"
			};

			inputData3 = std::vector<std::string>
			{
				"fs-end",
				"he-DX",
				"fs-he",
				"start-DX",
				"pj-DX",
				"end-zg",
				"zg-sl",
				"zg-pj",
				"pj-he",
				"RW-he",
				"fs-DX",
				"pj-RW",
				"zg-RW",
				"start-pj",
				"he-WI",
				"zg-he",
				"pj-fs",
				"start-RW"
			};
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart1(inputData1);

			// Assert:
			Assert::AreEqual(10ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(19ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(226ull, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart2(inputData1);

			// Assert:
			Assert::AreEqual(36ull, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart2(inputData2);

			// Assert:
			Assert::AreEqual(103ull, result);
		}

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			PassagePathing day12;

			// Act:
			uint64_t result = day12.GetResultOnPart2(inputData3);

			// Assert:
			Assert::AreEqual(3509ull, result);
		}
	};

	std::vector<std::string> Day12::inputData1 = std::vector<std::string>();
	std::vector<std::string> Day12::inputData2 = std::vector<std::string>();
	std::vector<std::string> Day12::inputData3 = std::vector<std::string>();
}