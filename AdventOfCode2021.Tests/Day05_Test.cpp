#include "stdafx.h"
#include "Day05\Day05_HydrothermalVenture.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day05;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<HydroVentLine>(const HydroVentLine& hvl) { return to_wstring(hvl.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day05)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"0,9 -> 5,9",
				"8,0 -> 0,8",
				"9,4 -> 3,4",
				"2,2 -> 2,1",
				"7,0 -> 7,4",
				"6,4 -> 2,0",
				"0,9 -> 2,9",
				"3,4 -> 1,4",
				"0,0 -> 8,8",
				"5,5 -> 8,2"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			HydroVentProcessor hvProc;

			// Act:
			std::vector<HydroVentLine> result = hvProc.Process(inputData);

			// Assert:
			Assert::AreEqual((size_t)10, result.size());
			Assert::AreEqual({ { 0,9 },{ 5,9 } }, result[0]);
			Assert::AreEqual({ { 2,2 },{ 2,1 } }, result[3]);
			Assert::AreEqual({ { 0,9 },{ 2,9 } }, result[6]);
			Assert::AreEqual({ { 5,5 },{ 8,2 } }, result[9]);
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			HydrothermalVenture day05;

			// Act:
			uint64_t result = day05.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(5ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			HydrothermalVenture day05;

			// Act:
			uint64_t result = day05.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(12ull, result);
		}
	};

	std::vector<std::string> Day05::inputData = std::vector<std::string>();
}