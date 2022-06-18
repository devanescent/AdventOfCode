#include "stdafx.h"
#include "Day13\Day13_MineCartMadness.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day13;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day13)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{ 
				"/->-\\        ",
				"|   |  /----\\",
				"| /-+--+-\\  |",
				"| | |  | v  |",
				"\\-+-/  \\-+--/",
				"  \\------/   "

			};

			inputData2 = std::vector<std::string>
			{
				"/>-<\\  ",
				"|   |  ",
				"| /<+-\\",
				"| | | v",
				"\\>+</ |",
				"  |   ^",
				"  \\<->/"
			};

			inputData3 = std::vector<std::string>
			{
				"/-\\  ",
				"\\>+-\\",
				"  \\</"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			MineCartMadness sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			MineCartMadness sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			MineCartMadness sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(0ull, result);
		}
	};

	std::vector<std::string> Year2018_Day13::inputData = std::vector<std::string>();
	std::vector<std::string> Year2018_Day13::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2018_Day13::inputData3 = std::vector<std::string>();
}