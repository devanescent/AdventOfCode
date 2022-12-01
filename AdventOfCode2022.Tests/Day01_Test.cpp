#include "stdafx.h"
#include "Day01\Day01_CalorieCounting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day01;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day01)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"1000",
				"2000",
				"3000",
				"",
				"4000",
				"",
				"5000",
				"6000",
				"",
				"7000",
				"8000",
				"9000",
				"",
				"10000"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CalorieCounting sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);
			// Assert:
			Assert::AreEqual(24000ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			CalorieCounting sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData);
			// Assert:
			Assert::AreEqual(45000ull, result);
		};

	};
	std::vector<std::string> Year2022_Day01::inputData = std::vector<std::string>();
}
