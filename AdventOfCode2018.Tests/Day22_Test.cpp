#include "stdafx.h"
#include "Day22\Day22_ModeMaze.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day22;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day22)
	{
	private:
		static std::vector<std::string> exampleData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			exampleData = std::vector<std::string>
			{
				"depth: 510",
				"target: 10,10"
			};
		}
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ModeMaze sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(exampleData);

			// Assert:
			Assert::AreEqual(114ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ModeMaze sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(exampleData);

			// Assert:
			Assert::AreEqual(45ull, result);
		}
	};

	std::vector<std::string> Year2018_Day22::exampleData = std::vector<std::string>();
}