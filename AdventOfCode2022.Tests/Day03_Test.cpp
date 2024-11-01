#include "stdafx.h"
#include "Day03/Day03_RucksackReorganization.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day03;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day03)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"vJrwpWtwJgWrhcsFMMfFFhFp",
				"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
				"PmmdzqPrVvPwwTWBwg",
				"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
				"ttgJtRGJQctTZtZT",
				"CrZsJsPPZsGzwwsLwLmpwMDw"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RucksackReorganization sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);
			// Assert:
			Assert::AreEqual(157ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RucksackReorganization sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);
			// Assert:
			Assert::AreEqual(70ull, result);
		};
	};

	std::vector<std::string> Year2022_Day03::inputData;
}
