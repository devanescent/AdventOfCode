#include "stdafx.h"
#include "Day21\Day21_FractalArt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day21;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day21)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"../.# => ##./#../...",
				".#./..#/### => #..#/..../..../#..#"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			FractalArt sut;
			sut.SetIterations(2);
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(12ull, result);
		};

	};
	std::vector<std::string> Year2017_Day21::inputData1 = std::vector<std::string>();
}
