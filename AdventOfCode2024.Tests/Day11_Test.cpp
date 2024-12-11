#include "stdafx.h"
#include "Day11/Day11_PlutonianPebbles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day11;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day11)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"125 17"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PlutonianPebbles sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(55312ull, result);
		};
	};
	std::vector<std::string> Year2024_Day11::inputData1;
}
