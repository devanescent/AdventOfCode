#include "stdafx.h"
#include "Day25/Day25_FullOfHotAir.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day25;
using namespace std::string_literals;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day25)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1=-0-2",
				"12111",
				"2=0=",
				"21",
				"2=01",
				"111",
				"20012",
				"112",
				"1=-1=",
				"1-12",
				"12",
				"1=",
				"122"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			FullOfHotAir sut;
			// Act:
			std::string result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual("2=-1=0"s, result);
		};
	};

	std::vector<std::string> Year2022_Day25::inputData1;
}
