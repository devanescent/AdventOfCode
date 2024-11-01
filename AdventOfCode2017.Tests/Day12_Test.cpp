#include "stdafx.h"
#include "Day12/Day12_DigitalPlumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day12;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day12)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0 <-> 2",
				"1 <-> 1",
				"2 <-> 0, 3, 4",
				"3 <-> 2, 4",
				"4 <-> 2, 3, 6",
				"5 <-> 6",
				"6 <-> 4, 5"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			DigitalPlumber sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(6ull, result);
		};
	};
	std::vector<std::string> Year2017_Day12::inputData1;
}
