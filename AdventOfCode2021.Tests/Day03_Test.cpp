#include "stdafx.h"
#include "Day03/Day03_BinaryDiagnostic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day03;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day03)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"00100",
				"11110",
				"10110",
				"10111",
				"10101",
				"01111",
				"00111",
				"11100",
				"10000",
				"11001",
				"00010",
				"01010"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			BinaryDiagnostic day03;

			// Act:
			uint64_t result = day03.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(198ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			BinaryDiagnostic day03;

			// Act:
			uint64_t result = day03.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(230ull, result);
		}
	};

	std::vector<std::string> Day03::inputData;
}