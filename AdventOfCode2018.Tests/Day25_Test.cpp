#include "stdafx.h"
#include "Day25/Day25_FourDimensionalAdventure.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day25;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day25)
	{
	private:
		static std::vector<std::string> example1Data;
		static std::vector<std::string> example2Data;
		static std::vector<std::string> example3Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			example1Data = std::vector<std::string>
			{
				"-1,2,2,0",
				"0,0,2,-2",
				"0,0,0,-2",
				"-1,2,0,0",
				"-2,-2,-2,2",
				"3,0,2,-1",
				"-1,3,2,2",
				"-1,0,-1,0",
				"0,2,1,-2",
				"3,0,0,0"
			};

			example2Data = std::vector<std::string>
			{
				"1,-1,0,1",
				"2,0,-1,0",
				"3,2,-1,0",
				"0,0,3,1",
				"0,0,-1,-1",
				"2,3,-2,0",
				"-2,2,0,",
				"2,-2,0,-1",
				"1,-1,0,-1",
				"3,2,0,2"
			};

			example3Data = std::vector<std::string>
			{
				"1,-1,-1,-2",
				"-2,-2,0,1",
				"0,2,1,3",
				"-2,3,-2,1",
				"0,2,3,-2",
				"-1,-1,1,-2",
				"0,-2,-1,0",
				"-2,2,3,-1",
				"1,2,2,0",
				"-1,-2,0,-2"
			};
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			FourDimensionalAdventure sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(4ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			FourDimensionalAdventure sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example2Data);

			// Assert:
			Assert::AreEqual(3ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			FourDimensionalAdventure sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example3Data);

			// Assert:
			Assert::AreEqual(8ull, result);
		}
	};

	std::vector<std::string> Year2018_Day25::example1Data;
	std::vector<std::string> Year2018_Day25::example2Data;
	std::vector<std::string> Year2018_Day25::example3Data;
}