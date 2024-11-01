#include "stdafx.h"
#include "Day16\Day16_ChronalClassification.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day16;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day16)
	{
	private:
		static std::vector<std::string> example1Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			example1Data = std::vector<std::string>
			{
				"Before: [3, 2, 1, 1]",
				"9 2 1 2",
				"After:  [3, 2, 2, 1]"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ChronalClassification sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(1ull, result);
		}
	};

	std::vector<std::string> Year2018_Day16::example1Data;
}