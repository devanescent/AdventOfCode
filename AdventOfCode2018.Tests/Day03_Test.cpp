#include "stdafx.h"
#include "Day03\Day03_NoMatterHowYouSliceIt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day03;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<RectangleClaim>(const RectangleClaim& rc) { return to_wstring(rc.ToString()); }

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day03)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;
		static std::vector<std::string> inputData6;
		static std::vector<std::string> inputData7;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			// Example from problem description:
			inputData = std::vector<std::string>
			{
				"#1 @ 1,3: 4x4",
				"#2 @ 3,1: 4x4",
				"#3 @ 5,5: 2x2"
			};

			// Non-overlapping claims:
			inputData2 = std::vector<std::string>
			{
				"#1 @ 1,3: 4x4",
				"#2 @ 2,15: 2x2"
			};

			// Claims with empty slices during the calculation
			inputData3 = std::vector<std::string>
			{
				"#1 @ 1,3: 2x2",
				"#2 @ 5,4: 2x2",
				"#3 @ 4,3: 2x4"
			};

			// Inverse order of removal: second claim gets removed from slice before the first
			inputData4 = std::vector<std::string>
			{
				"#1 @ 1,0: 10x5",
				"#2 @ 3,2: 5x2"
			};

			// Claims directly next to eachh other that do not overlap
			inputData5 = std::vector<std::string>
			{
				"#1 @ 1,0: 10x5",
				"#2 @ 11,0: 5x2",
				"#3 @ 16,0: 3x3"
			};

			// Multiple claims start and end at the same position
			inputData6 = std::vector<std::string>
			{
				"#1 @ 1,0: 5x5",
				"#2 @ 1,3: 5x2",
				"#3 @ 4,1: 3x3",
				"#4 @ 5,0: 2x2",
				"#5 @ 5,6: 4x2"
			};

			// Total overlap
			inputData7 = std::vector<std::string>
			{
				"#1 @ 1,1: 5x5",
				"#2 @ 1,1: 5x5",
				"#3 @ 1,1: 2x2"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			RectangleClaimProcessor rectClaimProc;

			// Act:
			std::vector<RectangleClaim> result = rectClaimProc.Process(inputData);

			// Assert:
			Assert::AreEqual(RectangleClaim(1, 1, 3, 4, 4), result[0]);
			Assert::AreEqual(RectangleClaim(2, 3, 1, 4, 4), result[1]);
			Assert::AreEqual(RectangleClaim(3, 5, 5, 2, 2), result[2]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(4ull, result);
		}

		TEST_METHOD(NonOverlappingClaims)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(EmptySlices)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(2ull, result);
		}

		TEST_METHOD(InverseOrderOfRemoval)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData4);

			// Assert:
			Assert::AreEqual(10ull, result);
		}

		TEST_METHOD(AdjacentClaimsNoOverlap)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData5);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(ClaimsStartAndEndAtSamePosition)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData6);

			// Assert:
			Assert::AreEqual(16ull, result);
		}

		TEST_METHOD(TotalOverlap)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData7);

			// Assert:
			Assert::AreEqual(25ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			NoMatterHowYouSliceIt day03;

			// Act:
			uint64_t result = day03.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(3ull, result);
		}
	};

	std::vector<std::string> Year2018_Day03::inputData = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData4 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData5 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData6 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day03::inputData7 = std::vector<std::string>();
}