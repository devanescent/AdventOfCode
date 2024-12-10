#include "stdafx.h"
#include "Day10/Day10_HoofIt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day10;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day10)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0123",
				"1234",
				"8765",
				"9876"
			};

			inputData2 = std::vector<std::string>
			{
				"...0...",
				"...1...",
				"...2...",
				"6543456",
				"7.....7",
				"8.....8",
				"9.....9"
			};

			inputData3 = std::vector<std::string>
			{
				"89010123",
				"78121874",
				"87430965",
				"96549874",
				"45678903",
				"32019012",
				"01329801",
				"10456732"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HoofIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HoofIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			HoofIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(36ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			HoofIt sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(81ull, result);
		};
	};
	std::vector<std::string> Year2024_Day10::inputData1;
	std::vector<std::string> Year2024_Day10::inputData2;
	std::vector<std::string> Year2024_Day10::inputData3;
}
