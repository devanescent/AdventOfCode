#include "stdafx.h"
#include "Day15\Day15_LensLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day15;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day15)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			LensLibrary sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1320ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			LensLibrary sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(145ull, result);
		};
	};
	std::vector<std::string> Year2023_Day15::inputData1 = std::vector<std::string>();
}
