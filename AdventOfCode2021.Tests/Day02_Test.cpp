#include "stdafx.h"
#include "Day02/Day02_Dive.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day02;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<DiveCmd>(const DiveCmd& dc) { return to_wstring(dc.ToString()); }

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day02)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"forward 5",
				"down 5",
				"forward 8",
				"up 3",
				"down 8",
				"forward 2"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			DiveCmdProcessor dcProc;

			// Act:
			std::vector<DiveCmd> result = dcProc.Process(inputData);

			// Assert:
			Assert::AreEqual(DiveCmd(DiveCmdDirection::Down, 5), result[1], L"Command no.2 incorrect!");
			Assert::AreEqual(DiveCmd(DiveCmdDirection::Forward, 8), result[2], L"Command no.3 incorrect!");
			Assert::AreEqual(DiveCmd(DiveCmdDirection::Up, 3), result[3], L"Command no.4 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			Dive day02;

			// Act:
			uint64_t result = day02.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(150ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			Dive day02;

			// Act:
			uint64_t result = day02.GetResultOnPart2(inputData);

			// Assert:
			Assert::AreEqual(900ull, result);
		}
	};

	std::vector<std::string> Day02::inputData;
}