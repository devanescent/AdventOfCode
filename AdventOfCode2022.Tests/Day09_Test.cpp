#include "stdafx.h"
#include "Day09\Day09_RopeBridge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day09;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day09)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"R 4",
				"U 4",
				"L 3",
				"D 1",
				"R 4",
				"D 1",
				"L 5",
				"R 2"
			};

			inputData2 = std::vector<std::string>
			{
				"R 5",
				"U 8",
				"L 8",
				"D 3",
				"R 17",
				"D 10",
				"L 25",
				"U 20"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RopeBridge sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(13ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RopeBridge sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			RopeBridge sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(36ull, result);
		};

	};

	std::vector<std::string> Year2022_Day09::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day09::inputData2 = std::vector<std::string>();
}
