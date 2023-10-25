#include "stdafx.h"
#include "Day24\Day24_ElectromagneticMoat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day24;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day24)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0/2",
				"2/2",
				"2/3",
				"3/4",
				"3/5",
				"0/1",
				"10/1",
				"9/10"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ElectromagneticMoat sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(31ull, result);
		};

	};
	std::vector<std::string> Year2017_Day24::inputData1 = std::vector<std::string>();
}
