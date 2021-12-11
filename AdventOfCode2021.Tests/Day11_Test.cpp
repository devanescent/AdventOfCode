#include "stdafx.h"
#include "Day11\Day11_DumboOctopus.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day11;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day11)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"5483143223",
				"2745854711",
				"5264556173",
				"6141336146",
				"6357385478",
				"4167524645",
				"2176841721",
				"6882881134",
				"4846848554",
				"5283751526"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			DumboOctopus day11;

			// Act:
			uint64_t result = day11.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(1656ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			DumboOctopus day11;

			// Act:
			uint64_t result = day11.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(195ull, result);
		}
	};

	std::vector<std::string> Day11::inputData = std::vector<std::string>();
}