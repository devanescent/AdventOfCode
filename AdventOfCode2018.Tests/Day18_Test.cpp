#include "stdafx.h"
#include "Day18\Day18_SettlersOfTheNorthPole.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day18;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day18)
	{
	private:
		static std::vector<std::string> example1Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			example1Data = std::vector<std::string>
			{
				".#.#...|#.",
				".....#|##|",
				".|..|...#.",
				"..|#.....#",
				"#.#|||#|#|",
				"...#.||...",
				".|....|...",
				"||...#|.#|",
				"|.||||..|.",
				"...#.|..|."
			};
		}
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SettlersOfTheNorthPole sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(1147ull, result);
		}
	};

	std::vector<std::string> Year2018_Day18::example1Data = std::vector<std::string>();
}