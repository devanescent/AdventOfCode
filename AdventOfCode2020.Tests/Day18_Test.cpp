#include "stdafx.h"
#include "Day18\Day18_OperationOrder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day18;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day18)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"2 * 3 + (4 * 5)",
				"1 + (2 * 3) + (4 * (5 + 6))",
				"5 + (8 * 3 + 9 + 3 * 4 * 3)",
				"5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))",
				"((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2 "
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			OperationOrder day18;

			// Act:
			uint64_t result = day18.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(26386ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			OperationOrder day18;

			// Act:
			uint64_t result = day18.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(693942ull, result);
		}
	};

	std::vector<std::string> Day18::inputData = std::vector<std::string>();
}