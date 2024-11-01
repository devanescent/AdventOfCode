#include "stdafx.h"
#include "Day07/Day07_TheTreacheryOfWhales.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day07;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day07)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"16,1,2,0,4,2,7,1,2,14"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TheTreacheryOfWhales day07;

			// Act:
			uint64_t result = day07.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(37ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			TheTreacheryOfWhales day07;

			// Act:
			uint64_t result = day07.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(168ull, result);
		}
	};

	std::vector<std::string> Day07::inputData = std::vector<std::string>();
}