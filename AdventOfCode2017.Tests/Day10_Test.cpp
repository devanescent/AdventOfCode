#include "stdafx.h"
#include "Day10\Day10_KnotHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day10;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day10)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"3, 4, 1, 5"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			KnotHash sut;
			sut.SetNumberListLength(5);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(12ull, result);
		};

	};
	std::vector<std::string> Year2017_Day10::inputData1 = std::vector<std::string>();
}
