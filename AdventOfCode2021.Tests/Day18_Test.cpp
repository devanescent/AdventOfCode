#include "stdafx.h"
#include "Day18/Day18_Snailfish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day18;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<SnailfishNum>(const SnailfishNum& sfn) { return to_wstring(sfn.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day18)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			// Check for parsing:
			inputData = std::vector<std::string>
			{
				"[1,2]",
				"[[1,2],3]",
				"[9,[8,7]]",
				"[[1,9],[8,5]]",
				"[[[[1,2],[3,4]],[[5,6],[7,8]]],9]",
				"[[[9,[3,8]],[[0,9],6]],[[[3,7],[4,9]],3]]",
				"[[[[1,3],[5,3]],[[1,3],[8,7]]],[[[4,9],[6,9]],[[8,2],[7,3]]]]"
			};

			// Check for explode:
			inputData2 = std::vector<std::string>
			{
				"[[[[[9,8],1],2],3],4]",
				"[7,[6,[5,[4,[3,2]]]]]",
				"[[6,[5,[4,[3,2]]]],1]",
				"[[3,[2,[1,[7,3]]]],[6,[5,[4,[3,2]]]]]",
				"[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]"
			};

			// Check for splits:
			inputData3 = std::vector<std::string>
			{
				"[[[[0,7],4],[15,[0,13]]],[1,1]]"
			};

			// Check for adding
			inputData4 = std::vector<std::string>
			{
				"[[[0,[5,8]],[[1,7],[9,6]]],[[4,[1,2]],[[1,4],2]]]",
				"[[[5,[2,8]],4],[5,[[9,9],0]]]",
				"[6,[[[6,2],[5,6]],[[7,6],[4,7]]]]",
				"[[[6,[0,7]],[0,9]],[4,[9,[9,0]]]]",
				"[[[7,[6,4]],[3,[1,3]]],[[[5,5],1],9]]",
				"[[6,[[7,3],[3,2]]],[[[3,8],[5,7]],4]]",
				"[[[[5,4],[7,7]],8],[[8,3],8]]",
				"[[9,3],[[9,9],[6,[4,9]]]]",
				"[[2,[[7,7],7]],[[5,8],[[9,3],[0,2]]]]",
				"[[[[5,2],5],[8,[3,7]]],[[5,[7,5]],[4,4]]]"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			SnailfishNumberProcessor sfnProc;

			// Act:
			std::vector<std::unique_ptr<SnailfishNum>> result = sfnProc.Process(inputData);

			// Assert:
			Assert::AreEqual(std::string("[1,2]"), result[0]->ToString(), L"Snailfish number No. 1 incorrect!");
			Assert::AreEqual(std::string("[[1,2],3]"), result[1]->ToString(), L"Snailfish number No. 2 incorrect!");
			Assert::AreEqual(std::string("[9,[8,7]]"), result[2]->ToString(), L"Snailfish number No. 3 incorrect!");
			Assert::AreEqual(std::string("[[1,9],[8,5]]"), result[3]->ToString(), L"Snailfish number No. 4 incorrect!");
			Assert::AreEqual(std::string("[[[[1,2],[3,4]],[[5,6],[7,8]]],9]"), result[4]->ToString(), L"Snailfish number No. 5 incorrect!");
			Assert::AreEqual(std::string("[[[9,[3,8]],[[0,9],6]],[[[3,7],[4,9]],3]]"), result[5]->ToString(), L"Snailfish number No. 6 incorrect!");
			Assert::AreEqual(std::string("[[[[1,3],[5,3]],[[1,3],[8,7]]],[[[4,9],[6,9]],[[8,2],[7,3]]]]"), result[6]->ToString(), L"Snailfish number No. 7 incorrect!");
		}

		TEST_METHOD(ExplodeNum)
		{
			// Arrange:
			SnailfishNumberProcessor sfnProc;

			// Act:
			std::vector<std::unique_ptr<SnailfishNum>> result = sfnProc.Process(inputData2);
			result[0]->Explode();
			result[1]->Explode();
			result[2]->Explode();
			result[3]->Explode();
			result[4]->Explode();

			Assert::AreEqual(std::string("[[[[0,9],2],3],4]"), result[0]->ToString(), L"Snailfish number No. 1 exploded incorrectly!");
			Assert::AreEqual(std::string("[7,[6,[5,[7,0]]]]"), result[1]->ToString(), L"Snailfish number No. 2 exploded incorrectly!");
			Assert::AreEqual(std::string("[[6,[5,[7,0]]],3]"), result[2]->ToString(), L"Snailfish number No. 3 exploded incorrectly!");
			Assert::AreEqual(std::string("[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]"), result[3]->ToString(), L"Snailfish number No. 4 exploded incorrectly!");
			Assert::AreEqual(std::string("[[3,[2,[8,0]]],[9,[5,[7,0]]]]"), result[4]->ToString(), L"Snailfish number No. 5 exploded incorrectly!");
		}

		TEST_METHOD(SplitNum)
		{
			// Arrange:
			SnailfishNumberProcessor sfnProc;

			// Act:
			std::vector<std::unique_ptr<SnailfishNum>> result = sfnProc.Process(inputData3);
			result[0]->Split();

			// Assert:
			Assert::AreEqual(std::string("[[[[0,7],4],[[7,8],[0,13]]],[1,1]]"), result[0]->ToString(), L"Snailfish number No. 1 split incorrectly (first split)!");

			// Act:
			result[0]->Split();

			// Assert:
			Assert::AreEqual(std::string("[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]"), result[0]->ToString(), L"Snailfish number No. 1 split incorrectly (second split)!");
		}

		TEST_METHOD(AddSnailfishNums)
		{
			Snailfish day18;
			uint64_t result = day18.GetResultOnPart1(inputData4);
			Assert::AreEqual(4140ull, result);
		}

		TEST_METHOD(FindMaxMagnitude)
		{
			Snailfish day18;
			uint64_t result = day18.GetResultOnPart2(inputData4);
			Assert::AreEqual(3993ull, result);
		}
	};

	std::vector<std::string> Day18::inputData;
	std::vector<std::string> Day18::inputData2;
	std::vector<std::string> Day18::inputData3;
	std::vector<std::string> Day18::inputData4;
}