#include "stdafx.h"
#include "Day02\Day02_CubeConundrum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day02;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day02)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
				"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
				"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
				"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
				"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CubeConundrum sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(8ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			CubeConundrum sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(2286ull, result);
		};
	};
	std::vector<std::string> Year2023_Day02::inputData1 = std::vector<std::string>();
}
