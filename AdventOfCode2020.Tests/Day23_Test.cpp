#include "stdafx.h"
#include "Day23/Day23_CrabCups.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day23;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day23)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"389125467"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			IntProcessor<IntProcessingMode::ValuesAsDigits> intProc;

			// Act:
			std::vector<int> result = intProc.Process(inputData);

			// Assert:
			Assert::AreEqual(3, result[0], L"Digit no.1 incorrect!");
			Assert::AreEqual(8, result[1], L"Digit no.2 incorrect!");
			Assert::AreEqual(7, result[8], L"Digit no.9 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			CrabCups day23;

			// Act:
			uint64_t result = day23.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(67384529ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			CrabCups day23;

			// Act:
			uint64_t result = day23.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(149245887792ull, result);
		}
	};

	std::vector<std::string> Day23::inputData;
}