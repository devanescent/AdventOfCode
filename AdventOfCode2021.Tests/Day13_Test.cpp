#include "stdafx.h"
#include "Day13/Day13_TransparentOrigami.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day13;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<FoldInstruction>(const FoldInstruction& fi) { return to_wstring(fi.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day13)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"6,10",
				"0,14",
				"9,10",
				"0,3",
				"10,4",
				"4,11",
				"6,0",
				"6,12",
				"4,1",
				"0,13",
				"10,12",
				"3,4",
				"3,0",
				"8,4",
				"1,10",
				"2,14",
				"8,10",
				"9,0",
				"",
				"fold along y=7",
				"fold along x=5"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			OrigamiProcessor oriProc;

			// Act:
			auto result = oriProc.Process(inputData);

			// Assert:
			// Check lengths:
			Assert::AreEqual((size_t)15, result.second.size(), L"Paper height is wrong!");
			Assert::AreEqual((size_t)11, result.second[0].size(), L"Paper width (at the top) is wrong!");
			Assert::AreEqual((size_t)11, result.second[14].size(), L"Paper width (at the bottom) is wrong!");

			// Check some points:
			Assert::IsTrue(result.second[10][6]);
			Assert::IsTrue(result.second[12][10]);
			Assert::IsTrue(result.second[14][2]);

			// Check instructions:
			Assert::AreEqual(FoldInstruction(FoldDirection::Vertical, 7), result.first[0], L"Fold instruction no.1 incorrect!");
			Assert::AreEqual(FoldInstruction(FoldDirection::Horizontal, 5), result.first[1], L"Fold instruction no.2 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TransparentOrigami day13;

			// Act:
			uint64_t result = day13.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(17ull, result);
		}

	};

	std::vector<std::string> Day13::inputData;
}