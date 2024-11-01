#include "stdafx.h"
#include "Day16/Day16_PermutationPromenade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day16;
using namespace std::string_literals;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day16)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"s1,x3/4,pe/b"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PermutationPromenade sut;
			sut.SetPrgmCount(5);
			// Act:
			std::string result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual("baedc"s, result);
		};
	};

	std::vector<std::string> Year2017_Day16::inputData1;
}
