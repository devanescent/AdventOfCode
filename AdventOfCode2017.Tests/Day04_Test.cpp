#include "stdafx.h"
#include "Day04\Day04_HighEntropyPassphrases.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day04;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day04)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"aa bb cc dd ee"
			};

			inputData2 = std::vector<std::string>
			{
				"aa bb cc dd aa"
			};

			inputData3 = std::vector<std::string>
			{
				"aa bb cc dd aaa"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			HighEntropyPassphrases sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(1ull, result);
		};

	};
	std::vector<std::string> Year2017_Day04::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day04::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2017_Day04::inputData3 = std::vector<std::string>();
}
