#include "stdafx.h"
#include "Day19\Day19_GoWithTheFlow.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day19;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day19)
	{
	private:
		static std::vector<std::string> example1Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			example1Data = std::vector<std::string>
			{
				"#ip 0",
				"seti 5 0 1",
				"seti 6 0 2",
				"addi 0 1 0",
				"addr 1 2 3",
				"setr 1 0 0",
				"seti 8 0 4",
				"seti 9 0 5"
			};
		}
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			GoWithTheFlow sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(6ull, result);
		}
	};

	std::vector<std::string> Year2018_Day19::example1Data = std::vector<std::string>();
}