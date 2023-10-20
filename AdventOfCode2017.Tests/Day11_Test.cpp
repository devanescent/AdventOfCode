#include "stdafx.h"
#include "Day11\Day11_HexEd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day11;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day11)
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
				"ne,ne,ne"
			};

			inputData2 = std::vector<std::string>
			{
				"ne,ne,sw,sw"
			};

			inputData3 = std::vector<std::string>
			{
				"ne,ne,s,s"
			};

			inputData4 = std::vector<std::string>
			{
				"se,sw,se,sw,sw"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(2ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			HexEd sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

	};
	std::vector<std::string> Year2017_Day11::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day11::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day11::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day11::inputData4 = std::vector<std::string>();
}
