#include "stdafx.h"
#include "Day12/Day12_HotSprings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day12;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day12)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"???.### 1,1,3",
				".??..??...?##. 1,1,3",
				"?#?#?#?#?#?#?#? 1,3,1,6",
				"????.#...#... 4,1,1",
				"????.######..#####. 1,6,5",
				"?###???????? 3,2,1"
			};

			inputData2 = std::vector<std::string>
			{
				".#. 1"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HotSprings sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(21ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HotSprings sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(525152ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			HotSprings sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(1ull, result);
		};
	};

	std::vector<std::string> Year2023_Day12::inputData1;
	std::vector<std::string> Year2023_Day12::inputData2;
}
