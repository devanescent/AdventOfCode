#include "stdafx.h"
#include "Day14/Day14_DiskDefragmentation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day14;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day14)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"flqrgnkx"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			DiskDefragmentation sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(8108ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			DiskDefragmentation sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(1242ull, result);
		};
	};

	std::vector<std::string> Year2017_Day14::inputData1;
}
