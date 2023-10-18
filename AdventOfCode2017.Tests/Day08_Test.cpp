#include "stdafx.h"
#include "Day08\Day08_IHeardYouLikeRegisters.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day08;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day08)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"b inc 5 if a > 1",
				"a inc 1 if b < 5",
				"c dec -10 if a >= 1",
				"c inc -20 if c == 10"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			IHeardYouLikeRegisters sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			IHeardYouLikeRegisters sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(10ull, result);
		};
	};
	std::vector<std::string> Year2017_Day08::inputData1 = std::vector<std::string>();
}
