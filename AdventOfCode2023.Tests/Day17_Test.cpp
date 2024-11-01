#include "stdafx.h"
#include "Day17/Day17_ClumsyCrucible.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day17;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day17)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"2413432311323",
				"3215453535623",
				"3255245654254",
				"3446585845452",
				"4546657867536",
				"1438598798454",
				"4457876987766",
				"3637877979653",
				"4654967986887",
				"4564679986453",
				"1224686865563",
				"2546548887735",
				"4322674655533"
			};

			inputData2 = std::vector<std::string>
			{
				"111111111111",
				"999999999991",
				"999999999991",
				"999999999991",
				"999999999991"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ClumsyCrucible sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(102ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ClumsyCrucible sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(94ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			ClumsyCrucible sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(71ull, result);
		};
	};

	std::vector<std::string> Year2023_Day17::inputData1;
	std::vector<std::string> Year2023_Day17::inputData2;
}
