#include "stdafx.h"
#include "Day20/Day20_ARegularMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day20;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day20)
	{
	public:
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ARegularMap sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "^WNE$" });

			// Assert:
			Assert::AreEqual(3ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			ARegularMap sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "^ENWWW(NEEE|SSE(EE|N))$"});

			// Assert:
			Assert::AreEqual(10ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			ARegularMap sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "^ENNWSWW(NEWS|)SSSEEN(WNSE|)EE(SWEN|)NNN$" });

			// Assert:
			Assert::AreEqual(18ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			ARegularMap sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "^ESSWWN(E|NNENN(EESS(WNSE|)SSS|WWWSSSSE(SW|NNNE)))$" });

			// Assert:
			Assert::AreEqual(23ull, result);
		}

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			ARegularMap sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1({ "^WSSEESWWWNW(S|NENNEEEENN(ESSSSW(NWSW|SSEN)|WSWWN(E|WWS(E|SS))))$" });

			// Assert:
			Assert::AreEqual(31ull, result);
		}
	};
}