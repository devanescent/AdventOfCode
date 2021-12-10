#include "stdafx.h"
#include "Day08\Day08_SevenSegmentSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day08;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day08)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe",
				"edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc",
				"fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg",
				"fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb",
				"aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea",
				"fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb",
				"dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe",
				"bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef",
				"egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb",
				"gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SevenSegmentSearch day08;

			// Act:
			uint64_t result = day08.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(26ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			SevenSegmentSearch day08;

			// Act:
			uint64_t result = day08.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(0ull /*TODO*/, result);
		}
	};

	std::vector<std::string> Day08::inputData = std::vector<std::string>();
}