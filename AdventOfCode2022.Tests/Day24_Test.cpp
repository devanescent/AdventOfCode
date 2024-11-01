#include "stdafx.h"
#include "Day24/Day24_BlizzardBasin.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day24;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day24)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"#.######",
				"#>>.<^<#",
				"#.<..<<#",
				"#>v.><>#",
				"#<^v^^>#",
				"######.#"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			BlizzardBasin sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(18ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			BlizzardBasin sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(54ull, result);
		};
	};

	std::vector<std::string> Year2022_Day24::inputData1;
}
