#include "stdafx.h"
#include "Day19/Day19_ASeriesOfTubes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day19;
using namespace std::string_literals;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day19)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"     |          ",
				"     |  +--+    ",
				"     A  |  C    ",
				" F---|----E|--+ ",
				"     |  |  |  D ",
				"     +B-+  +--+ ",
				""
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ASeriesOfTubes sut;
			// Act:
			std::string result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual("ABCDEF"s, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ASeriesOfTubes sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(38ull, result);
		};
	};

	std::vector<std::string> Year2017_Day19::inputData1;
}
