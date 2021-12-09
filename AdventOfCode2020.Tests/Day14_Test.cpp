#include "stdafx.h"
#include "Day14\Day14_DockingData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day14;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<InitializationInstruction>(const InitializationInstruction& ins) { return to_wstring(ins.ToString()); }

namespace AdventOfCode::Year2020::Tests
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
				"mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X",
				"mem[8] = 11",
				"mem[7] = 101",
				"mem[8] = 0"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			InitializationProcessor inProc;

			// Act:
			std::pair<std::vector<InitializationInstruction>, InitializationContext> result = inProc.Process(inputData);

			// Assert: (note: instructions are processed in reverse order, only the first one for each memory address is kept)
			Assert::AreEqual(InitializationInstruction(8, 0), result.first[0], L"Instruction no.1 incorrect!");
			Assert::AreEqual(InitializationInstruction(7, 101), result.first[1], L"Instruction no.2 incorrect!");
		}

		TEST_METHOD(CheckContext_SetBits)
		{
			// Arrange:
			InitializationContext ctx(0b00000111, 0b11111111);	// sets last three bits to 1, no bits are cleared
			
			// Act:
			ctx.SetMemory(1, 1);

			// Assert:
			Assert::AreEqual((uint64_t)0b111, ctx.GetMemorySum());
		}

		TEST_METHOD(CheckContext_ClearBits)
		{
			// Arrange:
			InitializationContext ctx(0b00000000, 0b11111100);	// clears last two bits, no extra bits are set

			// Act:
			ctx.SetMemory(1, 0b111);

			// Assert:
			Assert::AreEqual((uint64_t)0b100, ctx.GetMemorySum());
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			DockingData day14;

			// Act:
			uint64_t result = day14.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(165ull, result);
		}
	};

	std::vector<std::string> Day14::inputData = std::vector<std::string>();
}