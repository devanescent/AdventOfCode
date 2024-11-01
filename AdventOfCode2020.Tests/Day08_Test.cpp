#include "stdafx.h"
#include "Day08/Day08_HandheldHalting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day08;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Instruction>(const Instruction& ins) { return to_wstring(ins.ToString()); }

namespace AdventOfCode::Year2020::Tests
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
				"nop +0",
				"acc +1",
				"jmp +4",
				"acc +3",
				"jmp -3",
				"acc -99",
				"acc +1",
				"jmp -4",
				"acc +6"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			InstructionProcessor instrProc;

			// Act:
			std::vector<Instruction> result = instrProc.Process(inputData);

			// Assert:
			Assert::AreEqual(Instruction(0, Instruction::InstrType::NOP, 0), result[0], L"Instruction data no.1 incorrect!");
			Assert::AreEqual(Instruction(2, Instruction::InstrType::JMP, 4), result[2], L"Instruction data no.3 incorrect!");
			Assert::AreEqual(Instruction(5, Instruction::InstrType::ACC, -99), result[5], L"Instruction data no.6 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			HandheldHalting sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(5ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			HandheldHalting sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(8ull, result);
		}
	};

	std::vector<std::string> Day08::inputData;
}