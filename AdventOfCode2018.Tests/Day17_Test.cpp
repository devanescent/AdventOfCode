#include "stdafx.h"
#include "Day17/Day17_ReservoirResearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day17;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day17)
	{
	private:
		static std::vector<std::string> example1Data;
		static std::vector<std::string> example2Data;
		static std::vector<std::string> example3Data;
		static std::vector<std::string> example4Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			// Example from site:
			example1Data = std::vector<std::string>
			{
				"x=495, y=2..7",
				"y=7, x=495..501",
				"x=501, y=3..7",
				"x=498, y=2..4",
				"x=506, y=1..2",
				"x=498, y=10..13",
				"x=504, y=10..13",
				"y=13, x=498..504"
			};

			// Nested reservoirs
			example2Data = std::vector<std::string>
			{
				"x=495, y=5..6",

				"x=492, y=12..20",
				"x=507, y=12..20",
				"y=20, x=493..506",

				"x=496, y=14..17",
				"x=503, y=14..17",
				"y=17, x=497..502"
			};

			// Reservoir with inner width = 1
			example3Data = std::vector<std::string>
			{
				"x=495, y=5..6",

				"x=499, y=12..14",
				"x=501, y=12..14",
				"y=15, x=499..501",
			};

			// Nested reservoirs with inner width = 1
			example4Data = std::vector<std::string>
			{
				"x=495, y=5..6",

				"x=492, y=12..20",
				"x=507, y=12..20",
				"y=20, x=493..506",

				"x=499, y=14..16",
				"x=501, y=14..16",
				"y=17, x=499..501"
			};
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ReservoirResearch sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(57ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ReservoirResearch sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example2Data);

			// Assert:
			Assert::AreEqual(140ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			ReservoirResearch sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example3Data);

			// Assert:
			Assert::AreEqual(22ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			ReservoirResearch sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example4Data);

			// Assert:
			Assert::AreEqual(145ull, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			ReservoirResearch sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(example1Data);

			// Assert:
			Assert::AreEqual(29ull, result);
		}
	};

	std::vector<std::string> Year2018_Day17::example1Data;
	std::vector<std::string> Year2018_Day17::example2Data;
	std::vector<std::string> Year2018_Day17::example3Data;
	std::vector<std::string> Year2018_Day17::example4Data;
}