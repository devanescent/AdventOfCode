#include "stdafx.h"
#include "Day02/Day02_InventoryManagementSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day02;
using namespace std::string_literals;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day02)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"abcdef",
				"bababc",
				"abbcde",
				"abcccd",
				"aabcdd",
				"abcdee",
				"ababab"
			};

			inputData2 = std::vector<std::string>
			{
				"abcde",
				"fghij",
				"klmno",
				"pqrst",
				"fguij",
				"axcye",
				"wvxyz"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			InventoryManagementSystem day02;

			// Act:
			uint64_t result = day02.GetResultOnPart1(inputData1);

			// Assert:
			Assert::AreEqual(12ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			InventoryManagementSystem day02;

			// Act:
			std::string result = day02.GetResultOnPart2(inputData2);

			// Assert:
			Assert::AreEqual("fgij"s, result);
		}
	};

	std::vector<std::string> Year2018_Day02::inputData1;
	std::vector<std::string> Year2018_Day02::inputData2;
}