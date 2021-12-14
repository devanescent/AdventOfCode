#include "stdafx.h"
#include "Day14\Day14_ExtendedPolymerization.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day14;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<PolymerRule>(const PolymerRule& pr) { return to_wstring(pr.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day14)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"NNCB",
				"",
				"CH -> B",
				"HH -> N",
				"CB -> H",
				"NH -> C",
				"HB -> C",
				"HC -> B",
				"HN -> C",
				"NN -> C",
				"BH -> H",
				"NC -> B",
				"NB -> B",
				"BN -> B",
				"BB -> N",
				"BC -> B",
				"CC -> N",
				"CN -> C"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			PolymerProcessor polyProc;

			// Act:
			auto result = polyProc.Process(inputData);

			// Assert:
			Assert::AreEqual(std::string("NNCB"), result.second, L"Polymer templae is wrong!");

			Assert::AreEqual(PolymerRule('C', 'H', 'B'), result.first[0], L"First rule is incorrect!");
			Assert::AreEqual(PolymerRule('H', 'H', 'N'), result.first[1], L"Second rule is incorrect!");
			Assert::AreEqual(PolymerRule('C', 'N', 'C'), result.first.back(), L"Last rule is incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ExtendedPolymerization day14;

			// Act:
			uint64_t result = day14.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(1588ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ExtendedPolymerization day14;

			// Act:
			uint64_t result = day14.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(2188189693529ull, result);
		}

	};

	std::vector<std::string> Day14::inputData = std::vector<std::string>();
}