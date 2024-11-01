#include "stdafx.h"
#include "Day25/Day25_SeaCucumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day25;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day25)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{ 
				"v...>>.vv>",
				".vv>>.vv..",
				">>.>v>...v",
				">>v>>.>.v.",
				"v>v.vv.v..",
				">.>>..v...",
				".vv..>.>v.",
				"v.v..>>v.v",
				"....v..v.>"
			};	
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SeaCucumber day25;

			// Act:
			uint64_t result = day25.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(58ull, result);
		}
	};

	std::vector<std::string> Day25::inputData;
}