#include "stdafx.h"
#include "Day08/Day08_ResonantCollinearity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day08;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day08)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"............",
				"........0...",
				".....0......",
				".......0....",
				"....0.......",
				"......A.....",
				"............",
				"............",
				"........A...",
				".........A..",
				"............",
				"............"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ResonantCollinearity sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(14ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ResonantCollinearity sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(34ull, result);
		};
	};
	std::vector<std::string> Year2024_Day08::inputData1;
}
