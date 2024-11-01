#include "stdafx.h"
#include "Day22/Day22_SandSlabs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day22;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day22)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1,0,1~1,2,1",
				"0,0,2~2,0,2",
				"0,2,3~2,2,3",
				"0,0,4~0,2,4",
				"2,0,5~2,2,5",
				"0,1,6~2,1,6",
				"1,1,8~1,1,9"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			SandSlabs sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(5ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			SandSlabs sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(7ull, result);
		};
	};

	std::vector<std::string> Year2023_Day22::inputData1;
}
