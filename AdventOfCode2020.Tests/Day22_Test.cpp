#include "stdafx.h"
#include "Day22\Day22_CrabCombat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day22;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Deck>(const Deck& d) { return to_wstring(d.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day22)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"Player 1:",
				"9",
				"2",
				"6",
				"3",
				"1",
				"",
				"Player 2:",
				"5",
				"8",
				"4",
				"7",
				"10"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			DeckProcessor deckProc;

			// Act:
			std::vector<Deck> result = deckProc.Process(inputData);

			// Assert
			Assert::AreEqual(Deck({ 9,2,6,3,1 }), result[0], L"Deck no.1 incorrect!");
			Assert::AreEqual(Deck({ 5,8,4,7,10 }), result[1], L"Deck no.2 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			CrabCombat day22;

			// Act:
			uint64_t result = day22.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(306ull, result);
		}
	};

	std::vector<std::string> Day22::inputData = std::vector<std::string>();
}