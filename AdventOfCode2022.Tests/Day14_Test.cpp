#include "stdafx.h"
#include "Day14/Day14_RegolithReservoir.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day14;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day14)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"498,4 -> 498,6 -> 496,6",
				"503,4 -> 502,4 -> 502,9 -> 494,9"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RegolithReservoir sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(24ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RegolithReservoir sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(93ull, result);
		};
	};

	std::vector<std::string> Year2022_Day14::inputData1;
}
