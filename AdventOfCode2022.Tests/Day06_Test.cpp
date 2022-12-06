#include "stdafx.h"
#include "Day06\Day06_TuningTrouble.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day06;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day06)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"mjqjpqmgbljsphdztnvjfqwrcgsmlb"
			};

			inputData2 = std::vector<std::string>
			{
				"bvwbjplbgvbhsrlpgdmjqwftvncz"
			};

			inputData3 = std::vector<std::string>
			{
				"nppdvjthqldpwncqszvftbrmjlhg"
			};

			inputData4 = std::vector<std::string>
			{
				"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"
			};

			inputData5 = std::vector<std::string>
			{
				"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(7ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(5ull, result);
		};

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData3);
			// Assert:
			Assert::AreEqual(6ull, result);
		};

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData4);
			// Assert:
			Assert::AreEqual(10ull, result);
		};

		TEST_METHOD(CheckExample5_Part1)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData5);
			// Assert:
			Assert::AreEqual(11ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(19ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData2);
			// Assert:
			Assert::AreEqual(23ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(23ull, result);
		};

		TEST_METHOD(CheckExample4_Part2)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData4);
			// Assert:
			Assert::AreEqual(29ull, result);
		};

		TEST_METHOD(CheckExample5_Part2)
		{
			// Arrange:
			TuningTrouble sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData5);
			// Assert:
			Assert::AreEqual(26ull, result);
		};

	};
	std::vector<std::string> Year2022_Day06::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day06::inputData2 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day06::inputData3 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day06::inputData4 = std::vector<std::string>();
	std::vector<std::string> Year2022_Day06::inputData5 = std::vector<std::string>();
}
