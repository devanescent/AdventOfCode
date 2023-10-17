#include "stdafx.h"
#include "Day01\Day01_InverseCaptcha.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day01;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day01)
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
				"1122"
			};

			inputData2 = std::vector<std::string>
			{
				"1111"
			};

			inputData3 = std::vector<std::string>
			{
				"1234"
			};

			inputData4 = std::vector<std::string>
			{
				"91212129"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(3ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(4ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			InverseCaptcha sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);
			// Assert:
			Assert::AreEqual(9ull, result);
		};

	};
	std::vector<std::string> Year2017_Day01::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day01::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day01::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day01::inputData4 = std::vector<std::string>();
}
