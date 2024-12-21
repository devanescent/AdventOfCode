#include "stdafx.h"
#include "Day21/Day21_KeypadConundrum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day21;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day21)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"029A",
				"980A",
				"179A",
				"456A",
				"379A"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			KeypadConundrum sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(126384ull, result);
		};
	};
	std::vector<std::string> Year2024_Day21::inputData1;
}
