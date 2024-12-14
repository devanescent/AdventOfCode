#include "stdafx.h"
#include "Day14/Day14_RestroomRedoubt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day14;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day14)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"p=0,4 v=3,-3",
				"p=6,3 v=-1,-3",
				"p=10,3 v=-1,2",
				"p=2,0 v=2,-1",
				"p=0,0 v=1,3",
				"p=3,0 v=-2,-2",
				"p=7,6 v=-1,-3",
				"p=3,0 v=-1,-2",
				"p=9,3 v=2,3",
				"p=7,3 v=-1,2",
				"p=2,4 v=2,-3",
				"p=9,5 v=-3,-3"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RestroomRedoubt sut;
			sut.SetArea(11, 7);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(12ull, result);
		};
	};
	std::vector<std::string> Year2024_Day14::inputData1;
}
