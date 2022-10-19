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
			std::vector<InitializationInstruction> result = inProc.Process(inputData);

			// Assert:
			Assert::AreEqual(InitializationInstruction("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X"), result[0], L"Instruction no.1 incorrect!");
			Assert::AreEqual(InitializationInstruction(8, 11), result[1], L"Instruction no.2 incorrect!");
			Assert::AreEqual(InitializationInstruction(7, 101), result[2], L"Instruction no.3 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			DockingData sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(165ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			DockingData sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(
			{
				"mask = 000000000000000000000000000000X1001X",
				"mem[42] = 100",
				"mask = 00000000000000000000000000000000X0XX",
				"mem[26] = 1",
			});

			// Assert:
			Assert::AreEqual(208ull, result);
		}
	};

	std::vector<std::string> Day14::inputData = std::vector<std::string>();
}