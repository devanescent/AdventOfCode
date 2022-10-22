#include "stdafx.h"
#include "Day17\Day17_ConvayCubes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day17;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<CubeCoords>(const CubeCoords& cc) { return to_wstring(cc.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day17)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				".#.",
				"..#",
				"###"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			CubeProcessor cProc;

			// Act:
			std::vector<CubeCoords> result = cProc.Process(inputData);

			// Assert:
			Assert::AreEqual(CubeCoords(1, 0, 0), result[0], L"Coords no.1 incorrect!");
			Assert::AreEqual(CubeCoords(2, 1, 0), result[1], L"Coords no.2 incorrect!");
			Assert::AreEqual(CubeCoords(0, 2, 0), result[2], L"Coords no.3 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ConvayCubes sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(112ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ConvayCubes sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(848ull, result);
		}
	};

	std::vector<std::string> Day17::inputData = std::vector<std::string>();
}