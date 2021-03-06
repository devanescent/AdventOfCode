#include "stdafx.h"
#include "Day17\Day17_TrickShot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day17;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day17)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>{ "target area: x=20..30, y=-10..-5" };	
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TrickShot day17;

			// Act:
			uint64_t result = day17.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(45ull, result);
		}
	};

	std::vector<std::string> Day17::inputData = std::vector<std::string>();
}