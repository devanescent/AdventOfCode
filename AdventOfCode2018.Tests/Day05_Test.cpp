#include "stdafx.h"
#include "Day05\Day05_AlchemicalReduction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day05;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day05)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"dabAcCaCBAcCcaDA"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			AlchemicalReduction day05;

			// Act:
			uint64_t result = day05.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(10ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			AlchemicalReduction day05;

			// Act:
			uint64_t result = day05.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(4ull, result);
		}
	};

	std::vector<std::string> Year2018_Day05::inputData = std::vector<std::string>();
}