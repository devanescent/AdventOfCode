#include "stdafx.h"
#include "Day12/Day12_GardenGroups.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day12;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day12)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"AAAA",
				"BBCD",
				"BBCC",
				"EEEC"
			};

			inputData2 = std::vector<std::string>
			{
				"OOOOO",
				"OXOXO",
				"OOOOO",
				"OXOXO",
				"OOOOO"
			};

			inputData3 = std::vector<std::string>
			{
				"RRRRIICCFF",
				"RRRRIICCCF",
				"VVRRRCCFFF",
				"VVRCCCJFFF",
				"VVVVCJJCFE",
				"VVIVCCJJEE",
				"VVIIICJJEE",
				"MIIIIIJJEE",
				"MIIISIJEEE",
				"MMMISSJEEE"
			};

			inputData4 = std::vector<std::string>
			{
				"EEEEE",
				"EXXXX",
				"EEEEE",
				"EXXXX",
				"EEEEE"
			};

			inputData5 = std::vector<std::string>
			{
				"AAAAAA",
				"AAABBA",
				"AAABBA",
				"ABBAAA",
				"ABBAAA",
				"AAAAAA"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(140ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(772ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(1930ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(80ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(436ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData4);
			// Assert:
			Assert::AreEqual(236ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData5);
			// Assert:
			Assert::AreEqual(368ull, result);
		};

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			GardenGroups sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(1206ull, result);
		};

	};
	std::vector<std::string> Year2024_Day12::inputData1;
	std::vector<std::string> Year2024_Day12::inputData2;
	std::vector<std::string> Year2024_Day12::inputData3;
	std::vector<std::string> Year2024_Day12::inputData4;
	std::vector<std::string> Year2024_Day12::inputData5;
}
