#include "stdafx.h"
#include "Day02\Day02_InventoryManagementSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day02;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day02)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"abcdef",
				"bababc",
				"abbcde",
				"abcccd",
				"aabcdd",
				"abcdee",
				"ababab"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			InventoryManagementSystem day02;

			// Act:
			uint64_t result = day02.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(12ull, result);
		}
	};

	std::vector<std::string> Year2018_Day02::inputData = std::vector<std::string>();
}