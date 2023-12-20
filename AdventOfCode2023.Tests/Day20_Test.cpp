#include "stdafx.h"
#include "Day20\Day20_PulsePropagation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day20;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day20)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"broadcaster -> a, b, c",
				"%a -> b",
				"%b -> c",
				"%c -> inv",
				"&inv -> a"
			};

			inputData2 = std::vector<std::string>
			{
				"broadcaster -> a",
				"%a -> inv, con",
				"&inv -> b",
				"%b -> con",
				"&con -> output"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PulsePropagation sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(32000000ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			PulsePropagation sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(11687500ull, result);
		};

	};
	std::vector<std::string> Year2023_Day20::inputData1 = std::vector<std::string>();
	std::vector<std::string> Year2023_Day20::inputData2 = std::vector<std::string>();
}
