#include "stdafx.h"
#include "Day06/Day06_Lanternfish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day06;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day06)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"3,4,3,1,2"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			Lanternfish day06;

			// Act:
			uint64_t result = day06.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(5934ull, result);
		}
	};

	std::vector<std::string> Day06::inputData;
}