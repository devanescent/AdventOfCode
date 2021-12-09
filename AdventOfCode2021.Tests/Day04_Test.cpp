#include "stdafx.h"
#include "Day04\Day04_GiantSquid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day04;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<std::vector<int>>(const std::vector<int>& vec) 
{ 
	std::stringstream result;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(result, " "));	// includes trailing space, but which does not matter for comparison
	return to_wstring(result.str()); 
}

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<BingoBoard>(const BingoBoard& bb) { return to_wstring(bb.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day04)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
				"",
				"22 13 17 11  0",
				" 8  2 23  4 24",
				"21  9 14 16  7",
				" 6 10  3 18  5",
				" 1 12 20 15 19",
				"",
				" 3 15  0  2 22",
				" 9 18 13 17  5",
				"19  8  7 25 23",
				"20 11 10 24  4",
				"14 21 16 12  6",
				"",
				"14 21 17 24  4",
				"10 16 15  9 19",
				"18  8 23 26 20",
				"22 11 13  6  5",
				" 2  0 12  3  7"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			BingoProcessor bProc;

			// Act:
			std::pair<std::vector<BingoBoard>, std::vector<int>> result = bProc.Process(inputData);

			// Assert:
			Assert::AreEqual(
				BingoBoard
				{ 
					std::vector<std::vector<BingoBoardNum>>
					{
						{22, 13, 17, 11,  0},
						{ 8,  2, 23,  4, 24},
						{ 21, 9, 14, 16,  7},
						{ 6, 10,  3, 18,  5},
						{ 1, 12, 20, 15, 19}
					}
				}, result.first[0]
			);

			Assert::AreEqual(
				BingoBoard
				{ 
					std::vector<std::vector<BingoBoardNum>>
					{
						{14, 21, 17, 24,  4},
						{10, 16, 15,  9, 19},
						{18,  8, 23, 26, 20},
						{22, 11, 13,  6,  5},
						{ 2,  0, 12,  3,  7}
					}
				}, result.first[2]
			);

			Assert::AreEqual(std::vector<int> {7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1}, result.second);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			GiantSquid day04;

			// Act:
			uint64_t result = day04.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(4512ull, result);
		}
	};

	std::vector<std::string> Day04::inputData = std::vector<std::string>();
}