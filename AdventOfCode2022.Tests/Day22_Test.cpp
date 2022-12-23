#include "stdafx.h"
#include "Day22\Day22_MonkeyMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day22;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day22)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"        ...#",
				"        .#..",
				"        #...",
				"        ....",
				"...#.......#",
				"........#...",
				"..#....#....",
				"..........#.",
				"        ...#....",
				"        .....#..",
				"        .#......",
				"        ......#.",
				"",
				"10R5L5R10L4R5L5"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MonkeyMap sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(6032ull, result);
		};

	};
	std::vector<std::string> Year2022_Day22::inputData1 = std::vector<std::string>();
}
