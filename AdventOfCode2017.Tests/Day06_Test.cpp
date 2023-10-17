#include "stdafx.h"
#include "Day06\Day06_MemoryReallocation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day06;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day06)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"0 2 7 0"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			MemoryReallocation sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(5ull, result);
		};

	};
	std::vector<std::string> Year2017_Day06::inputData1 = std::vector<std::string>();
}
