#include "stdafx.h"
#include "Day13\Day13_PacketScanners.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day13;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day13)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0: 3",
				"1: 2",
				"4: 4",
				"6: 4"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PacketScanners sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(24ull, result);
		};

	};
	std::vector<std::string> Year2017_Day13::inputData1 = std::vector<std::string>();
}
