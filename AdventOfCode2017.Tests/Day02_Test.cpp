#include "stdafx.h"
#include "Day02\Day02_CorruptionChecksum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day02;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day02)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"5 1 9 5",
				"7 5 3",
				"2 4 6 8"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			CorruptionChecksum sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(18ull, result);
		};

	};
	std::vector<std::string> Year2017_Day02::inputData1 = std::vector<std::string>();
}
