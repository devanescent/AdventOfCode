#include "stdafx.h"
#include "Day02\Day02_RockPaperScissors.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day02;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day02)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"A Y",
				"B X",
				"C Z"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RockPaperScissors sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);
			// Assert:
			Assert::AreEqual(15ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RockPaperScissors sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);
			// Assert:
			Assert::AreEqual(15ull, result);
		};

	};
	std::vector<std::string> Year2022_Day02::inputData = std::vector<std::string>();
}
