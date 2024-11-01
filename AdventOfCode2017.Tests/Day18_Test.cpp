#include "stdafx.h"
#include "Day18/Day18_Duet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day18;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day18)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"set a 1",
				"add a 2",
				"mul a a",
				"mod a 5",
				"snd a",
				"set a 0",
				"rcv a",
				"jgz a -1",
				"set a 1",
				"jgz a -2"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Duet sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(4ull, result);
		};

	};
	std::vector<std::string> Year2017_Day18::inputData1;
}
