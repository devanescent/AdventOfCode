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

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			MathExpressionProcessor mathProc;

			// Act:
			std::vector<std::string> result = mathProc.Process(inputData);

			// Assert
			Assert::AreEqual(std::string("23*45*+"), result[0], L"Expression no.1 incorrect!");
			Assert::AreEqual(std::string("583*9+3+4*3*+"), result[2], L"Expression no.3 incorrect!");
			Assert::AreEqual(std::string("24+9*69+8*6+*6+2+4+2*"), result[4], L"Expression no.5 incorrect!");
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
	};

	std::vector<std::string> Day18::inputData = std::vector<std::string>();
}