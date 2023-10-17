#include "stdafx.h"
#include "Day03\Day03_SpiralMemory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day03;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day03)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"1"
			};

			inputData2 = std::vector<std::string>
			{
				"12"
			};

			inputData3 = std::vector<std::string>
			{
				"23"
			};

			inputData4 = std::vector<std::string>
			{
				"1024"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			SpiralMemory sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);
			// Assert:
			Assert::AreEqual(31ull, result);
		};

	};
	std::vector<std::string> Year2017_Day03::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day03::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day03::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day03::inputData4 = std::vector<std::string>();
}
