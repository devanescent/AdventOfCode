#include "stdafx.h"
#include "Day11/Day11_CosmicExpansion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day11;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day11)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"...#......",
				".......#..",
				"#.........",
				"..........",
				"......#...",
				".#........",
				".........#",
				"..........",
				".......#..",
				"#...#....."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CosmicExpansion sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(374ull, result);
		};
	};

	std::vector<std::string> Year2023_Day11::inputData1;
}
