#include "stdafx.h"
#include "Day09\Day09_SmokeBasin.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day09;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<HeatMapNode>(const HeatMapNode& node) { return to_wstring(node.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day09)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"2199943210",
				"3987894921",
				"9856789892",
				"8767896789",
				"9899965678"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			HeatMapProcessor hmProc;

			// Act:
			auto result = hmProc.Process(inputData);

			// Assert:
			Assert::AreEqual((size_t)5, result.size(), L"Number of heat map rows incorrct!");
			Assert::AreEqual((size_t)10, result[0].size(), L"Number of heat map cols incorrct!");
			Assert::AreEqual(HeatMapNode(2), result[0][0], L"Heat map node(0|0) incorrect!");
			Assert::AreEqual(HeatMapNode(9), result[1][1], L"Heat map node(1|1) incorrect!");
			Assert::AreEqual(HeatMapNode(8), result[4][9], L"Heat map node(9|4) incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SmokeBasin day09;

			// Act:
			uint64_t result = day09.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(15ull, result);
		}
	};

	std::vector<std::string> Day09::inputData = std::vector<std::string>();
}