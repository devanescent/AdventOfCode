#include "stdafx.h"
#include "Day10\Day10_SyntaxScoring.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day10;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day10)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"[({(<(())[]>[[{[]{<()<>>",
				"[(()[<>])]({[<{<<[]>>(",
				"{([(<{}[<>[]}>{[]{[(<()>",
				"(((({<>}<{<{<>}{[]{[]{}",
				"[[<[([]))<([[{}[[()]]]",
				"[{[{({}]{}}([{[{{{}}([]",
				"{<[[]]>}<{[{[{[]{()[[[]",
				"[<(<(<(<{}))><([]([]()",
				"<{([([[(<>()){}]>(<<{{",
				"<{([{{}}[<[[[<>{}]]]>[]]"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SyntaxScoring day10;

			// Act:
			uint64_t result = day10.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(26397ull, result);
		}
	};

	std::vector<std::string> Day10::inputData = std::vector<std::string>();
}