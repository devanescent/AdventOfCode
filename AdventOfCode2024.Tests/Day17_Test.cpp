#include "stdafx.h"
#include "Day17/Day17_ChronospatialComputer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day17;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day17)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Register A: 729",
				"Register B: 0",
				"Register C: 0",
				"",
				"Program: 0,1,5,4,3,0"
			};

			inputData2 = std::vector<std::string>
			{
				"Register A: 2024",
				"Register B: 0",
				"Register C: 0",
				"",
				"Program: 0,3,5,4,3,0"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ChronospatialComputer sut;
			// Act:
			std::string result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(std::string("4,6,3,5,6,3,5,2,1,0"), result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ChronospatialComputer sut;
			// Act:
			std::string result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(std::string("117440"), result);
		};
	};
	std::vector<std::string> Year2024_Day17::inputData1;
	std::vector<std::string> Year2024_Day17::inputData2;
}
