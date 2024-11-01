#include "stdafx.h"
#include "Day16/Day16_TheFloorWillBeLava.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day16;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day16)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				".|...\\....",
				"|.-.\\.....",
				".....|-...",
				"........|.",
				"..........",
				".........\\",
				"..../.\\\\..",
				".-.-/..|..",
				".|....-|.\\",
				"..//.|...."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			TheFloorWillBeLava sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(46ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			TheFloorWillBeLava sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(51ull, result);
		};
	};

	std::vector<std::string> Year2023_Day16::inputData1;
}
