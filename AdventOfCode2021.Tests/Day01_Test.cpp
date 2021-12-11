#include "stdafx.h"
#include "Day01\Day01_SonarSweep.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day01;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day01)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"199",
				"200",
				"208",
				"210",
				"200",
				"207",
				"240",
				"269",
				"260",
				"263"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SonarSweep day01;

			// Act:
			uint64_t result = day01.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(7ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			SonarSweep day01;

			// Act:
			uint64_t result = day01.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(5ull, result);
		}
	};

	std::vector<std::string> Day01::inputData = std::vector<std::string>();
}