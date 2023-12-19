#include "stdafx.h"
#include "Day19\Day19_Aplenty.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day19;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day19)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"px{a<2006:qkq,m>2090:A,rfg}",
				"pv{a>1716:R,A}",
				"lnx{m>1548:A,A}",
				"rfg{s<537:gd,x>2440:R,A}",
				"qs{s>3448:A,lnx}",
				"qkq{x<1416:A,crn}",
				"crn{x>2662:A,R}",
				"in{s<1351:px,qqz}",
				"qqz{s>2770:qs,m<1801:hdj,R}",
				"gd{a>3333:R,R}",
				"hdj{m>838:A,pv}",
				"",
				"{x=787,m=2655,a=1222,s=2876}",
				"{x=1679,m=44,a=2067,s=496}",
				"{x=2036,m=264,a=79,s=2244}",
				"{x=2461,m=1339,a=466,s=291}",
				"{x=2127,m=1623,a=2188,s=1013}"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Aplenty sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(19114ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			Aplenty sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(167409079868000ull, result);
		};

	};
	std::vector<std::string> Year2023_Day19::inputData1 = std::vector<std::string>();
}
