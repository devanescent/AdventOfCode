#include "stdafx.h"
#include "Day21/Day21_MonkeyMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day21;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day21)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"root: pppw + sjmn",
				"dbpl: 5",
				"cczh: sllz + lgvd",
				"zczc: 2",
				"ptdq: humn - dvpt",
				"dvpt: 3",
				"lfqf: 4",
				"humn: 5",
				"ljgn: 2",
				"sjmn: drzm * dbpl",
				"sllz: 4",
				"pppw: cczh / lfqf",
				"lgvd: ljgn * ptdq",
				"drzm: hmdt - zczc",
				"hmdt: 32"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MonkeyMath sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(152ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			MonkeyMath sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(301ull, result);
		};
	};

	std::vector<std::string> Year2022_Day21::inputData1;
}
