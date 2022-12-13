#include "stdafx.h"
#include "Day13\Day13_DistressSignal.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day13;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day13)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"[1,1,3,1,1]",
				"[1,1,5,1,1]",
				"",
				"[[1],[2,3,4]]",
				"[[1],4]",
				"",
				"[9]",
				"[[8,7,6]]",
				"",
				"[[4,4],4,4]",
				"[[4,4],4,4,4]",
				"",
				"[7,7,7,7]",
				"[7,7,7]",
				"",
				"[]",
				"[3]",
				"",
				"[[[]]]",
				"[[]]",
				"",
				"[1,[2,[3,[4,[5,6,7]]]],8,9]",
				"[1,[2,[3,[4,[5,6,0]]]],8,9]"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			DistressSignal sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(13ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			DistressSignal sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(140ull, result);
		};

	};
	std::vector<std::string> Year2022_Day13::inputData1 = std::vector<std::string>();
}
