#include "stdafx.h"
#include "Day22/Day22_SporificaVirus.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day22;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day22)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"..#",
				"#..",
				"..."
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			SporificaVirus sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(5587ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			SporificaVirus sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(2511944ull, result);
		};
	};
	std::vector<std::string> Year2017_Day22::inputData1;
}
