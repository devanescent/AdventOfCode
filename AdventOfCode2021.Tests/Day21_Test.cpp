#include "stdafx.h"
#include "Day21\Day21_DiracDice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day21;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day21)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{ 
				"Player 1 starting position: 4",
				"Player 2 starting position: 8"
			};	
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			DiracDice day21;

			// Act:
			uint64_t result = day21.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(739785ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			DiracDice day21;

			// Act:
			uint64_t result = day21.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(444356092776315ull, result);
		}
	};

	std::vector<std::string> Day21::inputData = std::vector<std::string>();
}