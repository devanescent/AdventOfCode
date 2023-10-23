#include "stdafx.h"
#include "Day17\Day17_Spinlock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day17;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day17)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"3"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Spinlock sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(638ull, result);
		};

	};
	std::vector<std::string> Year2017_Day17::inputData1 = std::vector<std::string>();
}
