#include "stdafx.h"
#include "Day23/Day23_LANParty.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2024::Day23;
using namespace std::literals;

namespace AdventOfCode::Year2024::Tests
{
	TEST_CLASS(Year2024_Day23)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"kh-tc",
				"qp-kh",
				"de-cg",
				"ka-co",
				"yn-aq",
				"qp-ub",
				"cg-tb",
				"vc-aq",
				"tb-ka",
				"wh-tc",
				"yn-cg",
				"kh-ub",
				"ta-co",
				"de-co",
				"tc-td",
				"tb-wq",
				"wh-td",
				"ta-ka",
				"td-qp",
				"aq-cg",
				"wq-ub",
				"ub-vc",
				"de-ta",
				"wq-aq",
				"wq-vc",
				"wh-yn",
				"ka-de",
				"kh-ta",
				"co-tc",
				"wh-qp",
				"tb-vc",
				"td-yn"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			LANParty sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(7ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			LANParty sut;
			// Act:
			std::string result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual("co,de,ka,ta"s, result);
		};
	};
	std::vector<std::string> Year2024_Day23::inputData1;
}
