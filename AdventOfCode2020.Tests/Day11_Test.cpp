#include "stdafx.h"
#include "Day11\Day11_SeatingSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day11;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Seat>(const Seat& s) { return to_wstring(s.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day11)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"L.LL.LL.LL",
				"LLLLLLL.LL",
				"L.L.L..L..",
				"LLLL.LL.LL",
				"L.LL.LL.LL",
				"L.LLLLL.LL",
				"..L.L.....",
				"LLLLLLLLLL",
				"L.LLLLLL.L",
				"L.LLLLL.LL"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			SeatingProcessor seatsProc;

			// Act:
			std::vector<SeatRow> result = seatsProc.Process(inputData);

			// Assert:
			Assert::AreEqual(Seat(Seat::SeatType::EMPTY), result[0][0], L"Seat(r=0,c=0) incorrect!");
			Assert::AreEqual(Seat(Seat::SeatType::EMPTY), result[1][0], L"Seat(r=1,c=0) incorrect!");
			Assert::AreEqual(Seat(Seat::SeatType::NO_SEAT), result[0][1], L"Seat(r=0,c=1) incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SeatingSystem sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(37ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			SeatingSystem sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(26ull, result);
		}
	};

	std::vector<std::string> Day11::inputData = std::vector<std::string>();
}