#include "stdafx.h"
#include "Day07\Day07_HandyHaversacks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day07;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day07)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"light red bags contain 1 bright white bag, 2 muted yellow bags.",
				"dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
				"bright white bags contain 1 shiny gold bag.",
				"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
				"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
				"dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
				"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
				"faded blue bags contain no other bags.",
				"dotted black bags contain no other bags."
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			BagProcessor bagProc;

			// Act:
			std::vector<Bag*> result = bagProc.Process(inputData);

			// Assert
			// TODO...
			Assert::IsTrue(true);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			HandyHaversacks day07 = HandyHaversacks("shiny gold");

			// Act:
			uint64_t result = day07.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(4ull, result);
		}
	};

	std::vector<std::string> Day07::inputData = std::vector<std::string>();
}