#include "stdafx.h"
#include "Day25/Day25_TheHaltingProblem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day25;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day25)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Begin in state A.",
				"Perform a diagnostic checksum after 6 steps.",
				"",
				"In state A:",
				"  If the current value is 0:",
				"    - Write the value 1.",
				"    - Move one slot to the right.",
				"    - Continue with state B.",
				"  If the current value is 1:",
				"    - Write the value 0.",
				"    - Move one slot to the left.",
				"    - Continue with state B.",
				"",
				"In state B:",
				"  If the current value is 0:",
				"    - Write the value 1.",
				"    - Move one slot to the left.",
				"    - Continue with state A.",
				"  If the current value is 1:",
				"    - Write the value 1.",
				"    - Move one slot to the right.",
				"    - Continue with state A."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			TheHaltingProblem sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

	};
	std::vector<std::string> Year2017_Day25::inputData1;
}
