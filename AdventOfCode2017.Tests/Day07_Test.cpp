#include "stdafx.h"
#include "Day07\Day07_RecursiveCircus.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day07;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day07)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"pbga (66)",
				"xhth (57)",
				"ebii (61)",
				"havc (66)",
				"ktlj (57)",
				"fwft (72) -> ktlj, cntj, xhth",
				"qoyq (66)",
				"padx (45) -> pbga, havc, qoyq",
				"tknk (41) -> ugml, padx, fwft",
				"jptl (61)",
				"ugml (68) -> gyxo, ebii, jptl",
				"gyxo (61)",
				"cntj (57)"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			RecursiveCircus sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			RecursiveCircus sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(60ull, result);
		};
	};
	std::vector<std::string> Year2017_Day07::inputData1 = std::vector<std::string>();
}
