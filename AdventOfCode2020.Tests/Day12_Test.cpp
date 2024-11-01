#include "stdafx.h"
#include "Day12/Day12_RainRisk.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day12;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<NavInstruction>(const NavInstruction& navIns) { return to_wstring(navIns.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day12)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"F10",
				"N3",
				"F7",
				"R90",
				"F11"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			NavInstructionProcessor navProc;

			// Act:
			std::vector<NavInstruction> result = navProc.Process(inputData);

			// Assert:
			Assert::AreEqual(NavInstruction(NavDirection::F, 10), result[0], L"Navigation instruction no.1 incorrect!");
			Assert::AreEqual(NavInstruction(NavDirection::N, 3), result[1], L"Navigation instruction no.2 incorrect!");
			Assert::AreEqual(NavInstruction(NavDirection::R, 90), result[3], L"Navigation instruction no.4 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			RainRisk sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(25ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			RainRisk sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(286ull, result);
		}
	};

	std::vector<std::string> Day12::inputData;
}