#include "stdafx.h"
#include "Day06/Day06_CustomCustoms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day06;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<AnswerSet>(const AnswerSet& ans) { return to_wstring(ans.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day06)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"abc",
				"",
				"a",
				"b",
				"c",
				"",
				"ab",
				"ac",
				"",
				"a",
				"a",
				"a",
				"a",
				"",
				"b"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			AnswerProcessor ansProc;

			// Act:
			std::vector<AnswerSet> result = ansProc.Process(inputData);

			// Assert:
			Assert::AreEqual(AnswerSet({ "abc" }), result[0], L"Answer set no.1 incorrect!");
			Assert::AreEqual(AnswerSet({ "a", "b", "c" }), result[1], L"Answer set no.2 incorrect!");
			Assert::AreEqual(AnswerSet({ "ab", "ac" }), result[2], L"Answer set no.3 incorrect!");
			Assert::AreEqual(AnswerSet({ "a", "a", "a", "a" }), result[3], L"Answer set no.4 incorrect!");
			Assert::AreEqual(AnswerSet({ "b" }), result[4], L"Answer set no.5 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			CustomCustoms day06;

			// Act:
			uint64_t result = day06.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(11ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			CustomCustoms day06;

			// Act:
			uint64_t result = day06.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(6ull, result);
		}
	};

	std::vector<std::string> Day06::inputData;
}

